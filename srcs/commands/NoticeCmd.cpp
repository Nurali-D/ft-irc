#include "NoticeCmd.hpp"


// MARK: - Class Constructor

NoticeCmd::NoticeCmd(std::vector<std::string> &args, User *user) : Command(NOTICE, args, user) {}


// MARK: - Class Distructor

NoticeCmd::~NoticeCmd(void) {}


// MARK: - Class Methods

std::string	NoticeCmd::getTopic(std::vector<std::string> &args) {
	std::vector<std::string>::iterator it;
	std::string topic;

	it += 2;
	if ((*it)[0] == '#')
		(*it).erase(0, 1);
	while (it != args.end()) {
		topic += (*it);
		if (it + 1 != args.end())
			topic += " ";
		++it;
	}
	return topic;
}

void	NoticeCmd::execute(void) {
	std::string target = args.at(1);
	std::string msg = getTopic(args);

	if (target.at(0) == '#') {
		Channel *channel = channelsList->getChannel(target);
		if (channel)
			channel->mailing(":" + user->getNickname() + " NOTICE " + target + " :" + msg, user);
		else
			user->appendMessage(":server " + std::string(ERR_NOSUCHCHANNEL) + " " + target + " : No such channel");
		return ;
	}

	User *userTarget = usersList->getUser(target);
	if (userTarget) {
		userTarget->appendMessage(":" + user->getNickname() + " NOTICE " + target + " :" + msg);
	} else {
		user->appendMessage(":server " + std::string(ERR_NOSUCHNICK) + " " + target + " : No such nick/channel");
	}
}
