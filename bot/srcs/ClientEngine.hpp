#include "ClientSocket.hpp"
#include <queue>

#ifndef CLIENTENGINE_HPP
# define CLIENTENGINE_HPP

class ClientEngine
{
public:
	ClientEngine(ClientSocket &cs);
	~ClientEngine();

private:
	int						kq;
	ClientSocket			cs;
	std::string				readedMsg;
	std::queue<std::string> sendMsgs;

	void		makeQueue();
	void		watchLoop();
	void		printError(const std::string &comment);
	void		readFromClientSocket(int i, struct kevent *eventList);
	std::string recv_msg(int fd, int size);
	void		writeToClientSocket(int i, struct kevent *eventList);
};

#endif