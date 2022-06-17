#include "ListCmd.hpp"


// MARK: - Class Constructor

ListCmd::ListCmd(std::vector<std::string> &args, User *user) : Command(LIST, args, user) {}


// MARK: - Class Destructor

ListCmd::~ListCmd(void) {}


// MARK: - Class Methods

std::string	ListCmd::itoa(int size) {
	std::ostringstream ss;
	ss << size;
	return ss.str();
}

void	ListCmd::execute(void) {
	if (user->getState() != User::ACTIVE)
		return ;
	
	if (args.size() == 2) {
		std::vector<Channel*> channels = channelsList->getChannels();
		std::vector<Channel*>::iterator it;
		user->appendMessage(":server " + std::string(RPL_LISTSTART) + " " 
			+ user->getNickname() + " Channel :Users Topic");
		for (it = channels.begin(); it != channels.end(); ++it) {
			user->appendMessage(":server " + std::string(RPL_LIST) + " " + user->getNickname() + " " 
				+ (*it)->getName() + " : " + itoa((*it)->getUsers().size()) + " " + (*it)->getTopic());
		}
		user->appendMessage(":server " + std::string(RPL_LISTEND)  + " " 
			+ user->getNickname() +  " :End of /LIST");
	} else {
		std::string channelTarget = args.at(1);
		Channel *channel = channelsList->getChannel(channelTarget);
		if (channel) {
			user->appendMessage(":server " + std::string(RPL_LISTSTART) + " " 
				+ user->getNickname() + " Channel :Users Topic");
			user->appendMessage(":server " + std::string(RPL_LIST) + " " 
				+ user->getNickname() + " " + channel->getName()
				+ " : " + itoa(channel->getUsers().size()) + " " + channel->getTopic());
			user->appendMessage(":server " + std::string(RPL_LISTEND) + " " 
				+ user->getNickname() + " :End of /LIST");
		} else {
			user->appendMessage(":server " + std::string(ERR_NOSUCHCHANNEL) + " " 
				+ user->getNickname() + " " + channelTarget + " : No such channel");
		}
	}
}
