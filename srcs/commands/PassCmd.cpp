#include "PassCmd.hpp"


// MARK: - Class Constructor

PassCmd::PassCmd(std::vector<std::string> &args, User *user) : Command(PASS, args, user) {}


// MARK: - Class Distructor

PassCmd::~PassCmd(void) {}


// MARK: - Class Methods

void PassCmd::execute()
{
	if (args.size() != 3)
		return ;
	if (args.at(1) != args.at(2)) {
		user->appendMessage(":server " + std::string(ERR_PASSWDMISMATCH) + " :Password incorrect!");
		user->appendMessage(":server KILL " + user->getAddress() + " :Bad password");
		return ;
	}
	if (user->getState() == User::ACTIVE)
		return ;

	user->setState(User::AUTH);
	if (user->isNickAndUsername()) {
		user->setState(User::ACTIVE);
		user->appendMessage(":server " + std::string(RPL_WELCOME) + " "
		+ user->getNickname() + " :Welcome to the Internet Relay Network "
		+ user->getNickname() + "!" + user->getHostname() + "@" + user->getAddress());
	}
}
