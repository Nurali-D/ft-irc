#include "JoinCmd.hpp"


// MARK: - Class Constructor

JoinCmd::JoinCmd(std::vector<std::string> &args, User *user) : Command(JOIN, args, user) {}


// MARK: - Class Distructor

JoinCmd::~JoinCmd(void) {}


// MARK: - Class Methods

void	JoinCmd::execute(void) {
	if (args.size() != 3)
		return ;

	if (args[1][0] != '#')
		return ;

	if (channelsList) {
		std::vector<Channel*>::iterator it;
		for (it = channelsList->begin(); it != channelsList->end(); ++it) {
			std::cout << (*it)->getName() << std::endl;
			if ((*it)->getName() == args[1])
				(*it)->addUser(user);
				user->appendChannel(*it);
				return;
		}
	}
	Channel *channel = new Channel(user, args[1]);
	channelsList->push_back(channel);
	channel->addUser(user);
	user->appendChannel(channel);
}
