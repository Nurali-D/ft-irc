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

	Channel *channel = channelsList->getChannel(args[1]);
	if (channel) {
		if (channel->getUser(user->getNickname()))
			return ;
		channel->addUser(user);
		user->appendChannel(channel);
		addJoinMessage();
		return ;
	}
	channelsList->addChannel(user, args[1]);
	addCreateMessage();
}

void JoinCmd::addCreateMessage() {
	user->appendMessage(":server " + std::string(RPL_YOUREOPER) + " :You are now an IRC operator");
	user->appendMessage(":" + user->getNickname() + "!~" + user->getUsername() +
		"@" + user->getHostname() + " JOIN :" + args.at(1));
	user->appendMessage(":server " + std::string(RPL_NAMREPLY) + 
		" " + user->getNickname() + " = " + args.at(1) + 
		" :@" + user->getNickname());
	user->appendMessage(":server " + std::string(RPL_TOPIC) + " " + user->getNickname() + " "
		+ args.at(1) + " :Undefined topic");
	user->appendMessage(":server " + std::string(RPL_ENDOFNAMES) + 
		" " + args.at(1) + " :End of /NAMES list.");
}

void JoinCmd::addJoinMessage() {
	std::string chUsers = getChannelUsers(args.at(1));

	user->appendMessage(":" + user->getNickname() + "!~" + user->getUsername() +
		"@" + user->getHostname() + " JOIN :" + args.at(1));
	user->appendMessage(":server " + std::string(RPL_NAMREPLY) + 
		" " + user->getNickname() + " = " + args.at(1) + " :" + chUsers);
	user->appendMessage(":server " + std::string(RPL_ENDOFNAMES) + 
	" " + args.at(1) + " :End of /NAMES list.");
}

std::string JoinCmd::getChannelUsers(std::string &channelName) {
	Channel *channel = channelsList->getChannel(channelName);

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
