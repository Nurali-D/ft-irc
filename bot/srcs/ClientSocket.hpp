#include "../headers/libraryHeaders.hpp"

#ifndef CLIENTSOCKET_HPP
# define CLIENTSOCKET_HPP

class ClientSocket
{
public:
	ClientSocket();
	ClientSocket(const char &ip, int port, std::string password);
	~ClientSocket();
	ClientSocket(const ClientSocket &other);
	ClientSocket	&operator=(const ClientSocket &other);
	int				getSocketFd() const;
	void			connectServer(const char &ip, int port);
	std::string		getPassword() const;
	int				getConnectFd() const;
private:
	int					clientSocketFd;
	int					connectFd;
	struct sockaddr_in	serverSocketAddr;
	std::string			password;
};

#endif