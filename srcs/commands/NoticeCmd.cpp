#include "NoticeCmd.hpp"


// MARK: - Class Constructor

NoticeCmd::NoticeCmd(std::vector<std::string> &args, User *user) : Command(NOTICE, args, user) {}


// MARK: - Class Distructor

NoticeCmd::~NoticeCmd(void) {}


// MARK: - Class Methods

void	NoticeCmd::execute(void) {
	if (args.size() != 4)
		return ;
	
	std::string nickname = args.at(1);
	std::string msg = args.at(2);

	User *userTarget = usersList->getUser(nickname);
	if (userTarget) {
		userTarget->appendMessage(":" + user->getNickname() + " NOTICE " + nickname + " :" + msg);
	} else {
		user->appendMessage(":server " + std::string(ERR_NOSUCHNICK) + " " + nickname + " : No such nick/channel");
	}
}
