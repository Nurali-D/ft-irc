#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "../headers/libraryHeaders.hpp"
#include "../client/Channel.hpp"
#include "../client/User.hpp"
#include "../client/UsersList.hpp"
#include "../client/ChannelsList.hpp"

class Command
{
	public:
		enum CmdType {
			PASS,
			NICK,
			USER,
			PRIVMSG,
			JOIN,
			PING,
			KICK,
			NOTICE,
			TOPIC,
			HEAD,
			QUIT,
			WHO,
			BOT
		};

	protected:
		CmdType cmd;
		std::vector<std::string> &args;
		User *user;

		UsersList		*usersList;
		ChannelsList	*channelsList;
		void 			addWelcomeMessage();

	private:
		static const std::string cmdsArray[];

	public:
		Command(CmdType cmd, std::vector<std::string> &args, User *user);
		virtual ~Command(void);

		virtual void execute() = 0;
		void setUsersList(UsersList *usersList);
		void setChannelsList(ChannelsList *channelsList);
		static Command *createCmd(std::string &cmdName, std::vector<std::string> &args, User *user);
};

#endif
