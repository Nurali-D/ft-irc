#include "Nick.hpp"

// MARK: - Class Constructor

NickCmd::NickCmd(const std::map<std::string, std::string> &args, User *user) : Command(NICK, args, user) {}


// MARK: - Class Distructor

NickCmd::~NickCmd(void) {}


// MARK: - Class Methods

void	NickCmd::execute()
{
	if (args["nickname"]) {
		user->setNickname(args["nickname"]);
		if (user->getState() == User::AUTH && user->isNickAndHostname()) {
			user->appendMessage(":server " + std::string(RPL_WELCOME) + " "
			+ user->getNickname() + " :Welcome to the Internet Relay Network "
			+ user->getNickname() + "!" + user->getHostname() + "@" + user->getAddress());
		}
	}
}
