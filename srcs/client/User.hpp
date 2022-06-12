#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include <stack>

#include "../headers/libraryHeaders.hpp"

class User;

#include "MessageHandler.hpp"

class User
{
	public:
		enum UserState {
			LOGGING,
			AUTH,
			ACTIVE,
			DEACTIVE,
		};

	private:
		int fd;
		struct sockaddr_in		address;
		User::UserState			state;
		std::string				nickname;
		std::string				username;
		std::string				hostname;
		std::string				servername;
		std::string				realname;
		std::stack<std::string>	messages;
		MessageHandler			*msgHandler;
		std::vector<Channel*>	joinedChannels;

	public:
		User(int fd, struct sockaddr_in address);
		~User();

		// MARK: - setters
		void					setNickname(std::string nickname);
		void					setUsername(std::string username);
		void					setState(UserState state);
		void					setMsgHandler(MessageHandler *msgHandler);
		
		// MARK: - getters
		const std::string		&getNickname();
		const std::string		&getUsername();
		const std::string		&getHostname();
		std::stack<std::string>	&getMessages();
		const std::string		getAddress();
		const User::UserState	&getState();	
		MessageHandler			*getMsgHandler();		

		// MARK: - methods
		void					appendMessage(std::string message);
		bool					isNickAndHostname();
		
};

#endif
