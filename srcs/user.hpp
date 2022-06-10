#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include "../libraryHeaders.hpp"

class User
{
	private:
		int fd;
		struct sockaddr_in address;
		std::string nickname;
		std::string user;
		std::vector<std::string> messages;

	public:
		User(int fd, struct sockaddr_in address);
		~User();

		void setNickname(std::string nickname);
		void setUser(std::string user);
		void appendMessage(std::string message);
		std::string getNickname();
		std::string getUser();
		std::vector<std::string> getMessages();
};

#endif
