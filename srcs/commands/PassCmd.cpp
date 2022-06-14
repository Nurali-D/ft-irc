#include "PassCmd.hpp"


// MARK: - Class Constructor

PassCmd::PassCmd(std::vector<std::string> &args, User *user) : Command(PASS, args, user) {}


// MARK: - Class Distructor

PassCmd::~PassCmd(void) {}


// MARK: - Class Methods

void PassCmd::execute()
{
	std::cout << "user pass: " << args.at(1).size() << " - server pass: " << args.at(2).size() << std::endl;
	if (args.size() != 3) {
		user->appendMessage(":server " + std::string(ERR_NEEDMOREPARAMS) + " :Need more params!");
		return ;
	}
	std::string receivedPass = args.at(1);
	char zeroPos = receivedPass.at(0);
	// std::cout << zeroPos << std::endl;
	if (zeroPos == ':') {
		receivedPass = receivedPass.substr(1);
	}
	if (receivedPass != args.at(2)) {
		std::cout << "We are here" << std::endl;
		user->appendMessage(":server " + std::string(ERR_PASSWDMISMATCH) + " :Password incorrect!");
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
