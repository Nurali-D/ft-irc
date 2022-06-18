#include "FromBotCmd.hpp"
#include <algorithm>


// MARK: - Class Constructor

FromBotCmd::FromBotCmd(std::vector<std::string> &args, User *user) : Command(FROMBOT, args, user) {}


// MARK: - Class Distructor

FromBotCmd::~FromBotCmd(void) {}


// MARK: - Class Methods

void FromBotCmd::execute() {
	if (user->getState() != User::ACTIVE)
	return ;

	std::string from = args.at(1);
	std::string target = args.at(2);
	std::string msg = args.at(3);

	if (msg[0] == ':')
		msg.erase(0, 1);

	User *fromUser = usersList->getUser(from);
	User *targetUser = usersList->getUser(target);
	if (targetUser) {
		std::cout << "targetUser :" << targetUser->getNickname() << std::endl;
		targetUser->appendMessage(":" + fromUser->getNickname() + "!" + fromUser->getNickname()
			+ "@" + fromUser->getAddress() + " PRIVMSG " + target + " : " + msg);
	} else {
		targetUser->appendMessage(":server " + std::string(ERR_NOSUCHNICK) + " " + user->getNickname()
			+ " : No such nick/channel");
	}
}