#include "Privmsg.hpp"


// MARK: - Class Constructor

PrivmsgCmd::PrivmsgCmd(std::vector<std::string> &args, User *user) : Command(PRIVMSG, args, user) {}


// MARK: - Class Distructor

PrivmsgCmd::~PrivmsgCmd(void) {}


// MARK: - Class Methods

void	PrivmsgCmd::execute(void) {
	if (args.size() != 3)
		return ;
	
	std::string target = args.at(1);
	std::string msg = args.at(2);

	std::cout << "target: " + target + " - msg: " + msg << std::endl;

	if (target.at(0) == '#') {
		if (!channelsList) { return ; }
		
		std::vector<Channel*>::iterator it = channelsList->begin();
		for (it; it != channelsList->end(); ++it) {
			if ((*it)->getName() == target) {
				std::vector<User*>::iterator uit = (*it)->getUsers().begin();
				for (uit; uit != (*it)->getUsers().end(); ++uit) {
					if ((*uit)->getNickname() == user->getNickname())
						continue;
					(*uit)->appendMessage(msg);
				}
			}
		}
	} else {
		std::vector<User*>::iterator it = usersList->begin();
		for (it; it != usersList->end(); ++it) {
			if ((*it)->getNickname() == target)
				(*it)->appendMessage(msg);
		}
	}
}
