#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include <queue>

#include "../headers/libraryHeaders.hpp"

class Channel;
class User;
class ChannelsList;

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
		std::queue<std::string>	messages;
		MessageHandler			*msgHandler;
		std::vector<Channel*>	joinedChannels;
		std::string				type;

	public:
		User(int fd, struct sockaddr_in address);
		~User();

		std::string				readedMsg;

		// MARK: - setters
		void					setNickname(std::string nickname);
		void					setUsername(std::string username);
		void					setState(UserState state);
		void					setMsgHandler(MessageHandler *msgHandler);
		void					setType(std::string type);
		
		// MARK: - getters
		const std::string		&getNickname();
		const std::string		&getUsername();
		const std::string		&getHostname();
		std::queue<std::string>	&getMessages();
		const std::string		getAddress();
		const User::UserState	&getState();	
		MessageHandler			*getMsgHandler();	
		int						getFd();
		std::string				getType();
		// MARK: - methods
		void					appendMessage(std::string message);
		void					appendChannel(Channel *channel);
		bool					isNickAndUsername();
		bool					isOperator(std::string channelName);
		
};

#endif
