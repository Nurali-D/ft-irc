#include "PrivmsgCmd.hpp"


// MARK: - Class Constructor

PrivmsgCmd::PrivmsgCmd(std::vector<std::string> &args, User *user) : Command(PRIVMSG, args, user) {}


// MARK: - Class Distructor

PrivmsgCmd::~PrivmsgCmd(void) {}


// MARK: - Class Methods

void	PrivmsgCmd::execute(void) {
	if (args.size() != 4)
		return ;
	
	std::string target = args.at(1);
	std::string msg = args.at(2);

	if (msg[0] == ':')
		msg.erase(0, 1);

	if (target.at(0) == '#') {
		if (!channelsList) { return ; }
		
		Channel *channel = channelsList->getChannel(target);
		if (channel)
			channel->mailing(":" + user->getNickname() + " PRIVMSG " + target + " :" + msg, user);
		// note: добавить обработку ошибки несуществующего канала

	} else {
		User *targetUser = usersList->getUser(target);
		if (targetUser)
			targetUser->appendMessage(":" + user->getNickname() + "!" + user->getNickname()
			+ "@" + user->getAddress() + " PRIVMSG " + target + " :" + msg);
		// note: добавить обработку ошибки несуществующего пользователя
	}
}
