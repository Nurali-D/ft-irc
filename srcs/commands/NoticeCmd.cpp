#include "NoticeCmd.hpp"


// MARK: - Class Constructor

NoticeCmd::NoticeCmd(std::vector<std::string> &args, User *user) : Command(NOTICE, args, user) {}


// MARK: - Class Distructor

NoticeCmd::~NoticeCmd(void) {}


// MARK: - Class Methods

void	NoticeCmd::execute(void) {
	if (args.size() != 4)
		return ;

	std::string target = args.at(1);
	std::string msg = args.at(2);

	if (target.at(0) == '#') {
		Channel *channel = channelsList->getChannel(target);
		if (channel)
			channel->mailing(":" + user->getNickname() + " NOTICE " + target + " :" + msg, user);
		else
			user->appendMessage(":server " + std::string(ERR_NOSUCHCHANNEL) + " " + user->getNickname()
				+ " : No such channel");
		return ;
	}

	User *userTarget = usersList->getUser(target);
	if (userTarget) {
		userTarget->appendMessage(":" + user->getNickname() + " NOTICE " + target + " :" + msg);
	} else {
		user->appendMessage(":server " + std::string(ERR_NOSUCHNICK) + " " + user->getNickname()
			+ " : No such nick/channel");
	}
}
