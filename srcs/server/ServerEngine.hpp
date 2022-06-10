#include "../headers/libraryHeaders.hpp"
#include "ServerSocket.hpp"

#ifndef SERVERENGINE_HPP
# define SERVERENGINE_HPP

class ServerEngine
{
public:
	ServerEngine(ServerSocket &serverSocket);
	~ServerEngine();

private:
	ServerSocket	serverSocket;
	int				kq;
	int				flag; // temporary
	//Userlist
	//ChannelsList
	//BotsList
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
