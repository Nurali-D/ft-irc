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
		User &user;
		const CmdType &cmd;
		const std::map<std::string, std::string> &args;
		std::vector<User*> *usersList;
		std::vector<Channel*> *channelsList;

	public:
		Command(const CmdType &cmd, const std::map<std::string, std::string> &args, User &user);
		virtual ~Command(void);

		virtual void execute() = 0;
		void setUsersList(std::vector<User*> *usersList);
		void setChannelsList(std::vector<Channel*> *channelsList);

};

#endif
