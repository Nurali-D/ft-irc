#include "ClientEngine.hpp"

ClientEngine::ClientEngine(ClientSocket &cs) : cs(cs) {

}

ClientEngine::~ClientEngine() {}

void	ClientEngine::printError(const std::string &comment)
{
	std::cerr << comment << '\n';
}

void		ClientEngine::makeQueue() {
	struct kevent	clientEvent[2];

	kq = kqueue();
	if (kq == -1)
		return (printError("kqueue() error"));
	EV_SET(&clientEvent[0], cs.getSocketFd(), EVFILT_READ, EV_ADD, 0, 0, 0);
	EV_SET(&clientEvent[1], cs.getSocketFd(), EVFILT_WRITE, EV_ADD, 0, 0, 0);

	if (kevent(kq, clientEvent, 2, NULL, 0, NULL) == -1)
		return (printError("kevent() error 3"));
	watchLoop();
}

void		ClientEngine::watchLoop() {
	struct kevent		eventList[2];
	int					eventNumber;

	while (true)
	{
		eventNumber = kevent(kq, NULL, 0, eventList, 2, NULL);
		if (eventNumber < 1)
		{
			std::cerr << std::strerror(errno) << std::endl;
			return (printError("kevent() error 2"));
		}
		for (int i = 0; i < eventNumber; i++)
		{
			if (eventList[i].filter == EVFILT_READ)
				readFromClientSocket(i, eventList);
			else if (eventList[i].filter == EVFILT_WRITE)
				writeToClientSocket(i, eventList);
		}
	}
}

void	ClientEngine::readFromClientSocket(int i, struct kevent *eventList)
{
	if (eventList[i].flags & EV_EOF) {
		std::cerr << "Connection failed.";
		exit (-1);
	}
	std::string msg = recv_msg(eventList[i].ident, (int)eventList[i].data);
	std::cout << ">> " + msg << std::endl;
	readedMsg += msg;
	size_t pos = readedMsg.find("\r\n", 0);
	if (pos != std::string::npos) {
		// message parser
	}
	
}

std::string ClientEngine::recv_msg(int fd, int size)
{
	char buf[size + 1];
	bzero(buf, size + 1);
	if (recv(fd, buf, size, 0) == -1)
		printError("recv() error");
	std::string str = std::string(buf);
	return str;
}

void	ClientEngine::writeToClientSocket(int i, struct kevent *eventList)
{
	
	if (eventList[i].flags & EV_EOF) {
		std::cerr << "Connection failed.";
		exit (-1);
	}
	
	if (!sendMsgs.empty()) {
		std::string msg = sendMsgs.top();
		msg += "\r\n";
		sendMsgs.pop();
		ssize_t sended = send(eventList[i].ident, msg.c_str(), msg.length(), 0);
		if (sended == -1) {
			printError("send() error");
		}
	}
}