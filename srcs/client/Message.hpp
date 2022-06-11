#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <stack>
#include "../headers/libraryHeaders.hpp"
#include "User.hpp"
#include "Channel.hpp"

class Message
{

	private:
		User					*fromUser;
		std::string				msgToParse;
		std::vector<User*>		usersList;
		std::vector<Channel*>	channelsList;
		void					findCommand(std::vector<std::string> &cmdWithArgs);
		std::string				stringToLower(std::string &str);

	public:
		Message(User *fromUser, std::string msgToParse, 
			std::vector<User*> usersList, std::vector<Channel*> channelsList);
		~Message();

		void	parseMessage();
};

#endif
