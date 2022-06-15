#include "ClientSocket.hpp"

ClientSocket::ClientSocket() : clientSocketFd(-1), connectFd(-1) {}

ClientSocket::ClientSocket(const char &ip, int port, std::string password) {
	this->password = password;
	connectServer(ip, port);
}

ClientSocket::~ClientSocket() {}

ClientSocket::ClientSocket(const ClientSocket &other) {
	*this = other;
}

ClientSocket	&ClientSocket::operator=(const ClientSocket &other) {
	if (this != &other)
	{
		this->clientSocketFd = other.clientSocketFd;
		this->serverSocketAddr = other.serverSocketAddr;
		this->password = other.password;
	}
	return (*this);
}

int				ClientSocket::getSocketFd() const {
	return clientSocketFd;
}

void			ClientSocket::connectServer(const char &ip, int port) {
	clientSocketFd = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocketFd == -1)
		throw std::runtime_error("socket() error");
	memset(&serverSocketAddr, 0, sizeof(serverSocketAddr));
	int opt = 1;
	setsockopt(clientSocketFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	serverSocketAddr.sin_family = AF_INET;
	serverSocketAddr.sin_port = htons(port);
	serverSocketAddr.sin_addr.s_addr = inet_addr(&ip);

	if ((connectFd = connect(clientSocketFd, (struct sockaddr*)&serverSocketAddr,
			sizeof(serverSocketAddr))) < 0) {
		std::cerr << "Connection failed." << std::endl;
		return ;
    }
}

std::string		ClientSocket::getPassword() const {
	return password;
}

int			ClientSocket::getConnectFd() const {
	return connectFd;
}