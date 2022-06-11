#include "UserCmd.hpp"


// MARK: - Class Constructor

UserCmd::UserCmd(const std::map<std::string, std::string> &args, User *user) : Command(USER, args, user) {}


// MARK: - Class Destructor

UserCmd::~UserCmd(void) {}


// MARK: - Class Methods

void	UserCmd::execute(void)
{
	if (args["username"]) {
		user->setUsername(args["username"])
		if (user->getState() == User::AUTH && user->isNickAndHostname()) {
			user->appendMessage(":server " + std::string(RPL_WELCOME) + " "
			+ user->getNickname() + " :Welcome to the Internet Relay Network "
			+ user->getNickname() + "!" + user->getHostname() + "@" + user->getAddress());
		}
	}
}