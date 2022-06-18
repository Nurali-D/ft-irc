#include "PassCmd.hpp"


// MARK: - Class Constructor

PassCmd::PassCmd(std::vector<std::string> &args, User *user) : Command(PASS, args, user) {}


// MARK: - Class Distructor

PassCmd::~PassCmd(void) {}


// MARK: - Class Methods

void PassCmd::execute()
{
	if (args.size() != 3) {
		user->appendMessage(":server " + std::string(ERR_NEEDMOREPARAMS) + " " + user->getNickname()
			+ " :Need more params!");
		return ;
	}
	std::string receivedPass = args.at(1);
	char zeroPos = receivedPass.at(0);
	if (zeroPos == ':') {
		receivedPass = receivedPass.substr(1);
	}
	if (receivedPass == (args.at(2) + "bot")) {
		user->setType("bot");
	}
	else if (receivedPass != args.at(2)) {
		user->appendMessage(":server " + std::string(ERR_PASSWDMISMATCH) + " " + user->getNickname()
			+ " :Password incorrect!");
		user->appendMessage(":server KILL " + user->getAddress() + " :Bad password");
		user->setState(User::DEACTIVE);
		return ;
	}
	if (user->getState() == User::ACTIVE)
		return ;

	user->setState(User::AUTH);
	if (user->isNickAndUsername()) {
		user->setState(User::ACTIVE);
		addWelcomeMessage();
	}
}
