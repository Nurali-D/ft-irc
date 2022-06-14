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
		
		std::vector<Channel*>::iterator it;
		for (it = channelsList->begin(); it != channelsList->end(); ++it) {
			if ((*it)->getName() == target) {
				std::vector<User*>::iterator uit;
				for (uit = (*it)->getUsers().begin(); uit != (*it)->getUsers().end(); ++uit) {
					if ((*uit)->getNickname() == user->getNickname())
						continue;
					(*uit)->appendMessage(":" + user->getNickname() + " PRIVMSG " + target + " :" + msg);
				}
				return ;
			}
		}
	} else {
		std::vector<User*>::iterator it;
		for (it = usersList->begin(); it != usersList->end(); ++it) {
			if ((*it)->getNickname() == target) {
				(*it)->appendMessage(":" + user->getNickname() + "!" + user->getNickname() + "@" + user->getAddress() + " PRIVMSG " + target + " :" + msg);
				return ;
			}
		}
	}
}
