#include "ClientEngine.hpp"

ClientEngine::ClientEngine(ClientSocket &cs) : cs(cs) {
	sendMsgs.push("nick SuperBot");
	sendMsgs.push("user SuperBot");
	sendMsgs.push("pass " + cs.getPassword() + "bot");
	makeQueue();
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
		std::cerr << "Connection failed.\n";
		exit (-1);
	}
	readedMsg = recv_msg(eventList[i].ident, (int)eventList[i].data);
	// std::cout << "=======>\n" << readedMsg << "-------------" << std::endl;
	if (readedMsg.rfind(":server", 0) == std::string::npos) {
		parseMsg();
	}

}

void	ClientEngine::parseMsg() {
	std::string delimiter = " ";
	size_t pos = 0;
	std::string token;
	std::vector<std::string> cmdWithArgs;

	size_t positionToErase = readedMsg.find("\r\n");
	if (positionToErase != std::string::npos) {
		readedMsg.erase(positionToErase, 2);
	} else {
		positionToErase = readedMsg.find("\n");
		if (positionToErase != std::string::npos)
			readedMsg.erase(positionToErase, 1);
	}
	while ((pos = readedMsg.find(delimiter)) != std::string::npos) {
		if (readedMsg.find_first_not_of(" ") == 0) {
			token = readedMsg.substr(0, pos);
			char zeroPos = token.at(0);
			if (zeroPos != ':') {
				cmdWithArgs.push_back(token);
			} else if (cmdWithArgs.size() > 0) {
				cmdWithArgs.push_back(readedMsg);
				readedMsg = "";
				break;
			}
		}
		readedMsg.erase(0, pos + delimiter.length());
	}
	if (readedMsg != "") {
		cmdWithArgs.push_back(readedMsg);
	}
	for (size_t i = 0; i < cmdWithArgs.size(); ++i) {
		std::cout << i << "---->" << cmdWithArgs.at(i) << std::endl;
	}
	findCommand(cmdWithArgs);
}

void		ClientEngine::findCommand(std::vector<std::string> &cmdWithArgs) {
	std::string msg;
	size_t size = cmdWithArgs.size();
	if (size < 3) {
		
		msg = "Need more params. See \"bot help\"";
		sendMsgs.push("PRIVMSG " + cmdWithArgs.at(0) + " :" + msg);
		// std::cout << "findCommand test\n";
	}
	if (cmdWithArgs.at(2) == "help") {
		msg = "\nbot save_channel #channel_name - saves channel on server after quiting all users;\nbot voting #channel_name :question - sends to all channel's users question.";
		sendMsgs.push("PRIVMSG " + cmdWithArgs.at(0) + " :" + msg);
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
		 
		std::string msg = sendMsgs.front();
		msg += "\r\n";
		std::cout << "=========>" << msg;
		sendMsgs.pop();
		ssize_t sended = send(eventList[i].ident, msg.c_str(), msg.length(), 0);
		if (sended == -1) {
			printError("send() error");
		}
	}
}