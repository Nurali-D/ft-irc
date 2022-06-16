#include "ServerEngine.hpp"

ServerEngine::ServerEngine(ServerSocket &serverSocket) {
	this->serverSocket = serverSocket;
	makeQueue();
}

ServerEngine::~ServerEngine() {}

void	ServerEngine::printError(const std::string &comment) {
	std::cerr << comment << '\n';
}

void	ServerEngine::acceptNewClient(int i, struct kevent *eventList)
{
	int					newEventFd;
	struct sockaddr_in	addr;
	socklen_t			addrLen = sizeof(addr);
	struct kevent		evSet[2];

	newEventFd = accept(eventList[i].ident, (struct sockaddr*) &addr, &addrLen);
	if (newEventFd == -1)
	{
		std::cerr << std::strerror(errno) << std::endl;
		return (printError("accept() error"));
	}
	int opt = 1;
	setsockopt(newEventFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	User *user = new User(newEventFd, addr);
	usersList.addUser(user);
	EV_SET(&evSet[0], newEventFd, EVFILT_READ, EV_ADD, 0, 0, static_cast<void*>(user));
	EV_SET(&evSet[1], newEventFd, EVFILT_WRITE, EV_ADD, 0, 0, static_cast<void*>(user));
	if (kevent(kq, evSet, 2, NULL, 0, NULL) == -1)
		return (printError("kevent() error 1"));
}

void	ServerEngine::deleteEvent(int i, struct kevent *eventList)
{
	User *user = static_cast<User*>(eventList[i].udata);
	user->setState(User::DEACTIVE);

}

std::string ServerEngine::recv_msg(int fd, int size)
{
	char buf[size + 1];
	bzero(buf, size + 1);
	if (recv(fd, buf, size, 0) == -1)
		printError("recv() error");
	std::string str = std::string(buf);
	return str;
}

void	ServerEngine::readFromClientSocket(int i, struct kevent *eventList)
{
	if (eventList[i].flags & EV_EOF) {
		deleteEvent(i, eventList);
	}
	std::string msg = recv_msg(eventList[i].ident, (int)eventList[i].data);
	// std::cout << ">> " + msg << std::endl;
	User *user = static_cast<User*>(eventList[i].udata);

	user->readedMsg += msg;
	size_t pos = user->readedMsg.find("\r\n", 0);
	if (pos != std::string::npos) {
		
		MessageHandler *msgHandler = user->getMsgHandler();
		if (msgHandler == NULL) {
			msgHandler = new MessageHandler(user, &usersList, &channelsList, 
				serverSocket.getPassword());
		}
		std::cout << "received message :\n" << user->readedMsg << std::endl;
		while (pos != std::string::npos) {
			msgHandler->setMsgToParse(user->readedMsg.substr(0, pos + 2));
			msgHandler->parseMessage();
			user->readedMsg.erase(0, pos + 2);
			pos = user->readedMsg.find("\r\n", 0);
		}
		
		user->readedMsg = "";
	}
	
	for (size_t i = 0; i < usersList.size(); ++i) {
		User *u = usersList.at(i);
		std::cout << "user " << i << " nickname: " << u->getNickname()
			<< " username: " << u->getUsername() << " status: " << u->getState() << std::endl;
	}
}

void	ServerEngine::writeToClientSocket(int i, struct kevent *eventList)
{
	
	if (eventList[i].flags & EV_EOF)
		deleteEvent(i, eventList);
	User *user = static_cast<User*>(eventList[i].udata);
	if (!user->getMessages().empty()) {
		std::string msg = user->getMessages().front();
		msg += "\r\n";
		user->getMessages().pop();
		ssize_t sended = send(eventList[i].ident, msg.c_str(), msg.length(), 0);
		if (sended == -1) {
			printError("send() error");
		}
	}
	
	
}

void	ServerEngine::watchLoop()
{
	struct kevent		eventList[1024];
	int					eventNumber;

	while (true)
	{
		eventNumber = kevent(kq, NULL, 0, eventList, 1024, NULL);
		if (eventNumber < 1)
		{
			std::cerr << std::strerror(errno) << std::endl;
			return (printError("kevent() error 2"));
		}
		for (int i = 0; i < eventNumber; i++)
		{
			if (serverSocket.getSocketFd() == (int) eventList[i].ident)
				acceptNewClient(i, eventList);
			else if (eventList[i].filter == EVFILT_READ)
				readFromClientSocket(i, eventList);
			else if (eventList[i].filter == EVFILT_WRITE)
				writeToClientSocket(i, eventList);
		}
		usersList.removeNonactiveUsers(kq);
	}
}

void	ServerEngine::makeQueue()
{
	struct kevent	serverEvent;

	kq = kqueue();
	if (kq == -1)
		return (printError("kqueue() error"));
	EV_SET(&serverEvent, serverSocket.getSocketFd(),
				EVFILT_READ, EV_ADD, 0, 0, 0);

	if (kevent(kq, &serverEvent, 1, NULL, 0, NULL) == -1)
		return (printError("kevent() error 3"));
	watchLoop();
}