#include "MessageHandler.hpp"
#include "../commands/NickCmd.hpp"
#include "../commands/PassCmd.hpp"
#include "../commands/Privmsg.hpp"
#include "../commands/UserCmd.hpp"
#include "../commands/Command.hpp"

MessageHandler::MessageHandler(User *fromUser, std::vector<User*> *usersList, 
		std::vector<Channel*> *channelsList, std::string password) 
		: fromUser(fromUser), 
		usersList(usersList), 
		channelsList(channelsList) {
	this->password = password;
}

MessageHandler::~MessageHandler() {}

void	MessageHandler::setMsgToParse(std::string msgToParse) {
	this->msgToParse = msgToParse;
}

void	MessageHandler::parseMessage() {
	std::string delimiter = " ";
	size_t pos = 0;
	std::string token;
	std::vector<std::string> cmdWithArgs;

	size_t positionToErase = msgToParse.find("\r\n");
	if (positionToErase != std::string::npos) {
		msgToParse.erase(positionToErase, 2);
		// std::cout << "\\r\\n erased from:\n" << msgToParse << std::endl;
	}
	while ((pos = msgToParse.find(delimiter)) != std::string::npos) {
		if (msgToParse.find_first_not_of(" ") == 0) {
			token = msgToParse.substr(0, pos);
			char zeroPos = token.at(0);
			if (zeroPos != ':') {
				cmdWithArgs.push_back(token);
			} else if (cmdWithArgs.size() > 0) {
				// std::cout << "-------------------|" << msgToParse << "|" << std::endl;
				cmdWithArgs.push_back(msgToParse);
				msgToParse = "";
				break;
			}
		}
		msgToParse.erase(0, pos + delimiter.length());
	}
	if (msgToParse != "") {
		// msgToParse.erase(msgToParse.length() - 1, 1);
		cmdWithArgs.push_back(msgToParse);
	}
	cmdWithArgs.push_back(password);
	findCommand(cmdWithArgs);
}

void	MessageHandler::findCommand(std::vector<std::string> &cmdWithArgs) {
	std::string commandName = stringToLower(cmdWithArgs.at(0));
	
	Command *cmd = Command::createCmd(commandName, cmdWithArgs, fromUser);
	if (cmd != NULL) {
		cmd->execute();
	}
	// note: if (cmd == NULL) return error message to user
}

std::string MessageHandler::stringToLower(std::string &str) {
	char array[str.length() + 1];

	for (size_t i = 0; i < str.length(); ++i) {
		array[i] = std::tolower(str.at(i));
	}
	array[str.length()] = '\0';
	std::string ret = std::string(array);
	return ret;
}