#include "Pass.hpp"


// MARK: - Class Constructor

PassCmd::PassCmd(const std::map<std::string, std::string> &args, User *user) : Command(Command::PASS, args, user) {}


// MARK: - Class Distructor

PassCmd::~PassCmd(void) {}


// MARK: - Class Methods

void PassCmd::execute()
{
	if (args["pass"] && args["pass"] == args["server_pass"]) {
		if (user->getState() == User::ACTIVE) { return; }
		user->setState(User::AUTH);
		if (user->isNickAndHostname()) {
			user->setState(User::ACTIVE);
			user->appendMessage(":server " + std::string(RPL_WELCOME) + " "
			+ user->getNickname() + " :Welcome to the Internet Relay Network "
			+ user->getNickname() + "!" + user->getHostname() + "@" + user->getAddress());
		}
	} else {
		user->appendMessage(":server " + std::string(ERR_PASSWDMISMATCH) + " :Password incorrect!");
		user->appendMessage(":server KILL " + user->getAddress() + " :Bad password");
	}
}
