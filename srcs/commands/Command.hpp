#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "../headers/libraryHeaders.hpp"
#include "../client/Channel.hpp"
#include "../client/User.hpp"

class Command
{
	public:
		enum CmdType {
			PASS,
			NICK,
			USER,
			PRIVMSG
		};

	protected:
		CmdType cmd;
		std::vector<std::string> &args;
		User *user;

		std::vector<User*> *usersList;
		std::vector<Channel*> *channelsList;

	private:
		static const std::string cmdsArray[];

	public:
		Command(CmdType cmd, std::vector<std::string> &args, User *user);
		virtual ~Command(void);

		virtual void execute() = 0;
		void setUsersList(std::vector<User*> *usersList);
		void setChannelsList(std::vector<Channel*> *channelsList);
		static Command *createCmd(std::string &cmdName, std::vector<std::string> &args, User *user);
};

#endif
