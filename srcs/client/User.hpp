#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include <stack>
#include "../headers/libraryHeaders.hpp"

class User
{
	enum UserCondition {
		LOGGING,
		ACTIVE,
		DEACTIVE,
	};

	private:
		int fd;
		struct sockaddr_in		address;
		User::UserCondition		condition;
		std::string				nickname;
		std::string				hostname;
		std::string				servername;
		std::string				realname;
		std::stack<std::string>	messages;

	public:
		User(int fd, struct sockaddr_in address);
		~User();

		void					setNickname(std::string nickname);
		// void					setUser(std::string user);
		void					appendMessage(std::string message);
		std::string				getNickname();
		// std::string				getUser();
		std::stack<std::string>	&getMessages();
};

#endif
