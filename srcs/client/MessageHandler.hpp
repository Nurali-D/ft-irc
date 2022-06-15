#ifndef MESSAGE_HPP
#define MESSAGE_HPP



#include <stack>
#include "../headers/libraryHeaders.hpp"

// #include "../commands/NickCmd.hpp"
// #include "../commands/PassCmd.hpp"
// #include "../commands/Privmsg.hpp"
// #include "../commands/UserCmd.hpp"

class Command;
class MessageHandler;

#include "UsersList.hpp"
#include "ChannelsList.hpp"
#include "Channel.hpp"
#include "User.hpp"

class MessageHandler
{

	private:
		User			*fromUser;
		std::string		msgToParse;
		std::string		password;
		UsersList		*usersList;
		ChannelsList	*channelsList;

		void					findCommand(std::vector<std::string> &cmdWithArgs);
		std::string				stringToLower(std::string &str);
		Command					*createCommand(std::string &commandName);

	public:
		MessageHandler(User *fromUser, UsersList *usersList, 
			ChannelsList *channelsList, std::string password);
		~MessageHandler();

		void		parseMessage();
		void		setMsgToParse(std::string msgToParse);
};

#endif
