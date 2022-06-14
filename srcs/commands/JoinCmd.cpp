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
			if ((*it)->getName() == args[1]) {
				(*it)->addUser(user);
				user->appendChannel(*it);
				addJoinMessage();
				return;
			}
		}
	}
	Channel *channel = new Channel(user, args[1]);
	channelsList->push_back(channel);
	channel->addUser(user);
	user->appendChannel(channel);
	addCreateMessage();
	
}

void JoinCmd::addCreateMessage() {

	user->appendMessage(":server " + std::string(RPL_ENDOFNAMES) + 
		" " + args.at(1) + " :End of /NAMES list.");

	user->appendMessage(":server " + std::string(RPL_NAMREPLY) + 
		" " + user->getNickname() + " = " + args.at(1) + 
		" :@" + user->getNickname());

	user->appendMessage(":server MODE " + args.at(1) + " +nt");

	user->appendMessage(":" + user->getNickname() + "!~" + user->getUsername() +
		"@" + user->getHostname() + " JOIN :" + args.at(1));
}

void JoinCmd::addJoinMessage() {
	std::string chUsers = getChannelUsers(args.at(1));

	user->appendMessage(":server " + std::string(RPL_ENDOFNAMES) + 
	" " + args.at(1) + " :End of /NAMES list.");

	user->appendMessage(":server " + std::string(RPL_NAMREPLY) + 
		" " + user->getNickname() + " = " + args.at(1) + " :" + chUsers);

	user->appendMessage(":" + user->getNickname() + "!~" + user->getUsername() +
		"@" + user->getHostname() + " JOIN :" + args.at(1));
}

std::string JoinCmd::getChannelUsers(std::string &channelName) {
	Channel *channel = NULL;
	size_t size = channelsList->size();

	for (size_t i = 0; i < size; ++i) {
		channel = channelsList->at(i);
		if (channelName == channel->getName()) {
			break ;
		}
	}
	std::vector<User*> chUsers = channel->getUsers();
	User *chop = channel->getChannelOperator();
	std::string chopName = chop->getNickname();
	std::string ret = "";

	for (size_t i = 0; i < chUsers.size(); ++i) {
		User *tmp = chUsers.at(i);
		std::string tmpName = tmp->getNickname();
		if (tmpName != chopName) {
			ret += tmpName + " ";
		}
	}
	ret += "@" + chopName;
	return ret;
}


// channel creating

// join #mychan
// :lt!~ltulune@cloak-7A50E5F8.bb.netbynet.ru JOIN :#mychan
// :moo.slashnet.org MODE #mychan +nt 
// :moo.slashnet.org 353 lt = #mychan :@lt 
// :moo.slashnet.org 366 lt #mychan :End of /NAMES list.

// joining channel

// join #mychan
// :bb!~bbetsey@cloak-7A50E5F8.bb.netbynet.ru JOIN :#mychan
// :moo.slashnet.org 353 bb = #mychan :bb @lt 
// :moo.slashnet.org 366 bb #mychan :End of /NAMES list.
