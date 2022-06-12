#include "../headers/libraryHeaders.hpp"
#include "ServerSocket.hpp"
#include "../client/User.hpp"
#include "../client/Channel.hpp"
#include "../client/MessageHandler.hpp"

#ifndef SERVERENGINE_HPP
# define SERVERENGINE_HPP

class ServerEngine
{
public:
	ServerEngine(ServerSocket &serverSocket);
	~ServerEngine();

private:
	int						kq;
	ServerSocket			serverSocket;
	std::vector<User*>		usersList;
	std::vector<Channel*>	channelsList;
	std::string				readedMsg;

	void		makeQueue();
	void		watchLoop();
	void		acceptNewClient(int i, struct kevent *eventList);
	void		deleteEvent(int i, struct kevent *eventList);
	std::string recv_msg(int fd, int size);
	void		readFromClientSocket(int i, struct kevent *eventList);
	void		writeToClientSocket(int i, struct kevent *eventList);
	void		printError(const std::string &comment);

};

#endif
