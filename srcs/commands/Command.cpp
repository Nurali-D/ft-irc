#include "Command.hpp"


// MARK: - Class Constructor

Command::Command(const Command::CmdType &cmd, const std::map<std::string, std::string> &args, User *user)
:
	cmd(cmd),
	args(args),
	user(user)
{}


// MARK: - Class Distructor

Command::~Command(void) {}


// MARK: - Class Methods

void Command::setUsersList(std::vector<User*> &usersList)
{
	this->usersList = usersList;
}

void Command::setChannelsList(std::vector<Channel*> &channelsList)
{
	this->channelsList = channelsList;
}
