#include "KickCmd.hpp"


// MARK: - Class Constructor

KickCmd::KickCmd(std::vector<std::string> &args, User *user) : Command(KICK, args, user) {}


// MARK: - Class Distructor

KickCmd::~KickCmd(void) {}


// MARK: - Class Methods

void KickCmd::execute(void) {
	if (user->getState() != User::ACTIVE)
		return ;

	if (args.size() != 5)
		return ;
	
	std::string channelTarget = args.at(1);
	std::string nicknameTarget = args.at(2);
	std::string msg = args.at(3);

	Channel *channel = channelsList->getChannel(channelTarget);
	User *userTarget = usersList->getUser(nicknameTarget);

	if (!channel) {
		user->appendMessage(":server " + std::string(ERR_NOSUCHCHANNEL)
		+ " " + channelTarget + ": No such channel");
		return ;
	}

	if (!userTarget) {
		user->appendMessage(":server " + std::string(ERR_NOSUCHNICK)
		 + " " + nicknameTarget + ": No such nick/channel");
		return ;
	}

	if (user->isOperator(channelTarget)) {
		if (channel->getUser(nicknameTarget)) {
			channel->mailing(":" + user->getNickname() + " KICK "
			+ channelTarget + " " + nicknameTarget + " " + msg, NULL);
			channel->removeUser(nicknameTarget);
			return ;
		} else {
			user->appendMessage(":server " + std::string(ERR_USERNOTINCHANNEL)
			+ " " + nicknameTarget + " " + channelTarget + ": They aren't on that channel");
			return ;
		}
	}
	user->appendMessage(":server " + std::string(ERR_CHANOPRIVSNEEDED)
	+ " " + channelTarget + ": You're not channel operator");
}
