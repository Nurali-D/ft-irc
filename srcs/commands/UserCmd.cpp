#include "UserCmd.hpp"


// MARK: - Class Constructor

UserCmd::UserCmd(std::vector<std::string> &args, User *user) : Command(USER, args, user) {}


// MARK: - Class Destructor

UserCmd::~UserCmd(void) {}


// MARK: - Class Methods

void	UserCmd::execute(void) {
	if (args.size() < 2 || args.size() > 6)
		return ;

	user->setUsername(args.at(1));
	if (user->getState() == User::AUTH && user->isNickAndUsername()) {
		user->appendMessage(":server " + std::string(RPL_WELCOME) + " "
		+ user->getNickname() + " :Welcome to the Internet Relay Network "
		+ user->getNickname() + "!" + user->getHostname() + "@" + user->getAddress());
	}
}