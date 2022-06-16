#include "Command.hpp"
#include <algorithm>
#include "PassCmd.hpp"
#include "NickCmd.hpp"
#include "UserCmd.hpp"
#include "PrivmsgCmd.hpp"
#include "JoinCmd.hpp"
#include "PingCmd.hpp"
#include "KickCmd.hpp"
#include "NoticeCmd.hpp"
#include "TopicCmd.hpp"


// MARK: - Class Constructor


Command::Command(Command::CmdType cmd, std::vector<std::string> &args, User *user)
:
	cmd(cmd),
	args(args),
	user(user)
{}

const std::string Command::cmdsArray[] = {"pass", "nick", "user", "privmsg", "join", "ping", "kick", "notice", "topic"};
// note: индекс команд 
// в массиве cmdsArray должен совпадать c последовательностью в enum CmdType


// MARK: - Class Distructor

Command::~Command(void) {}


// MARK: - Class Methods

void Command::setUsersList(UsersList *usersList) {
	this->usersList = usersList;
}

void Command::setChannelsList(ChannelsList *channelsList) {
	this->channelsList = channelsList;
}

Command *Command::createCmd(std::string &cmdName, std::vector<std::string> &args, User *user) {
	int index;
	int arraySize = sizeof(cmdsArray) / sizeof(cmdsArray[0]);
	const std::string *cmdIter = std::find(cmdsArray, cmdsArray + arraySize, cmdName);

	index = (cmdIter != &cmdsArray[arraySize]) ? std::distance(cmdsArray, cmdIter) : -1;

	switch (index) {
		case PASS :
			return new PassCmd(args, user);
		case NICK :
			return new NickCmd(args, user);
		case USER :
			return new UserCmd(args, user);
		case PRIVMSG :
			return new PrivmsgCmd(args, user);
		case JOIN :
			return new JoinCmd(args, user);
		case PING :
			return new PingCmd(args, user);
		case KICK :
			return new KickCmd(args, user);
		case NOTICE :
			return new NoticeCmd(args, user);
		case TOPIC :
			return new TopicCmd(args, user);
		
		// note: добавлять сюда все остальные команды и в cmdsArray
	}
	return NULL;
}

void Command::addWelcomeMessage() {

	user->appendMessage(":server " + std::string(RPL_ENDOFMOTD) + " "
		+ user->getNickname() + " ::End of /MOTD command.");
	user->appendMessage(":server " + std::string(RPL_MOTD) + " "
		+ user->getNickname() + " :- EASY MESSENGER by bbetsey & ltulune -");
	user->appendMessage(":server " + std::string(RPL_MOTDSTART) + " "
		+ user->getNickname() + " :- Message of the Day -");
	user->appendMessage(":server 00" + std::string(RPL_WELCOME) + " "
		+ user->getNickname() + " :Welcome to the Internet Relay Network "
		+ user->getNickname() + "!" + user->getHostname() + "@" + user->getAddress());
}