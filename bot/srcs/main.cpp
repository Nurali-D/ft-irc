#include "ClientSocket.hpp"

bool portIsNumber(char *str);

int main(int argc, char *argv[]) {
		if (argc != 3) {
		std::cout << "Invalid input arguments!" << std::endl;
		std::cout << "Input <port> <password>" << std::endl;
		return (1);
	}
	if (!portIsNumber(argv[1])) {
		std::cout << "Invalid port number" << std::endl;
		return (1);
	}
	std::string str("127.0.0.1");
	const char* ip = str.c_str();
	std::string password(argv[2]);
	ClientSocket cs = ClientSocket(*ip, std::atoi(argv[1]), password);

	while (true) {
		
	}

}

bool portIsNumber(char *str) {
	for (size_t i = 0; i < std::strlen(str); ++i) {
		if (isdigit(str[i]) == 0) {
			return false;
		}
	}
	return true;
}



	// listenSocketFd = socket(AF_INET, SOCK_STREAM, 0);
	// if (listenSocketFd == -1)
	// 	throw std::runtime_error("socket() error");
	// memset(&listenSocketAddr, 0, sizeof(listenSocketAddr));
	// int opt = 1;
	// setsockopt(listenSocketFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	// listenSocketAddr.sin_family = AF_INET;
	// listenSocketAddr.sin_port = htons(port);
	// listenSocketAddr.sin_addr.s_addr = inet_addr(&ip);