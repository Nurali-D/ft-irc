#include "ClientSocket.hpp"
#include "ClientEngine.hpp"

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
	ClientEngine ce = ClientEngine(cs);
}

bool portIsNumber(char *str) {
	for (size_t i = 0; i < std::strlen(str); ++i) {
		if (isdigit(str[i]) == 0) {
			return false;
		}
	}
	return true;
}
