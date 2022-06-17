#include "WhoCmd.hpp"


// MARK: - Class Constructor

WhoCmd::WhoCmd(std::vector<std::string> &args, User *user) : Command(WHO, args, user) {}


// MARK: - Class Destructor

WhoCmd::~WhoCmd(void) {}


// MARK: - Class Methods

void	WhoCmd::execute(void) {
	if (user->getState() != User::ACTIVE)
		return ;

	if (args.size() == 2) {
		std::vector<User*> users = usersList->getUsers();
		std::stringstream ss;
		ss << users.size();
		std::string usersCount = ss.str();

		std::vector<User*>::iterator it;

		if (users.size() == 1)
			user->appendMessage(":server " + std::string(RPL_WHOREPLY) + " " + user->getNickname()
				+ " Server has : " + usersCount + " user.");
		else if (users.size() > 1)
			user->appendMessage(":server " + std::string(RPL_WHOREPLY) + " " + user->getNickname()
				+ " Server has : " + usersCount + " users.");

		for (it = users.begin(); it != users.end(); ++it)
			user->appendMessage(":server " + std::string(RPL_WHOREPLY) + " " + user->getNickname()
				+ " " + (*it)->getNickname() + " " + (*it)->getUsername() + "@" + (*it)->getAddress());

		user->appendMessage(":server " + std::string(RPL_ENDOFWHO) + " : End of WHO");
		
	} else {
		Channel *channel = channelsList->getChannel(args.at(1));
		if (!channel)
			user->appendMessage(":server " + std::string(ERR_NOSUCHCHANNEL) + " " + args.at(1) 
				+ ": No such channel!");
		else {
			std::vector<User*> users = channel->getUsers();
			
			std::stringstream ss;
			ss << users.size();
			std::string usersCount = ss.str();
			if (users.size() == 1)
				user->appendMessage(":server " + std::string(RPL_WHOREPLY) + " " + user->getNickname()
					+ " Channel " + channel->getName() + " has : " + usersCount + " user.");
			else if (users.size() > 1)
				user->appendMessage(":server " + std::string(RPL_WHOREPLY) + " " + user->getNickname()
					+ " Channel " + channel->getName() + " has : " + usersCount + " users.");
			
			std::vector<User*>::iterator it;
			std::string channelAdmin = channel->getChannelOperator()->getNickname();
			for (it = users.begin(); it != users.end(); ++it) {
				std::string prefix;
				if ((*it)->getNickname() == channelAdmin)
					prefix += "@";
				user->appendMessage(":server " + std::string(RPL_WHOREPLY) + " " + user->getNickname()
					+ " " + prefix + (*it)->getNickname() + " " + (*it)->getUsername() + "@" + (*it)->getAddress());
			}
			
			user->appendMessage(":server " + std::string(RPL_ENDOFWHO) + " " + user->getNickname()
				+ " : End of WHO");
		}
	}
}
