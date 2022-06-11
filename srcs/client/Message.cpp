#include "Message.hpp"

Message::Message(User *fromUser, std::string msgToParse, 
		std::vector<User*> usersList, std::vector<Channel*> channelsList) {
	this->fromUser = fromUser;
	this->msgToParse = msgToParse;
	this->usersList = usersList;
	this->channelsList = channelsList;
}

Message::~Message() {}

void	Message::parseMessage() {
	// fromUser->appendMessage("Parsed " + msgToParse);

	std::string delimiter = " ";
	size_t pos = 0;
	std::string token;
	std::vector<std::string> cmdWithArgs;

	while ((pos = msgToParse.find(delimiter)) != std::string::npos) {
		if (msgToParse.find_first_not_of(" ") == 0) {
			token = msgToParse.substr(0, pos);
			if (token.at(0) != ':') {
				cmdWithArgs.push_back(token);
				// std::cout << "|" << token << "|" << std::endl;
			} else if (cmdWithArgs.size() > 0) {
				msgToParse.erase(msgToParse.length() - 1, 1);
				cmdWithArgs.push_back(msgToParse);
				msgToParse = "";
				break;
			}
		}
		msgToParse.erase(0, pos + delimiter.length());
	}
	if (msgToParse != "") {
		msgToParse.erase(msgToParse.length() - 1, 1);
		cmdWithArgs.push_back(msgToParse);
	}
	// for (size_t i = 0; i < cmdWithArgs.size(); ++i) {
	// 	std::cout << "|" << cmdWithArgs.at(i) << "|" << std::endl;
	// }
	findCommand(cmdWithArgs);
}

void	Message::findCommand(std::vector<std::string> &cmdWithArgs) {
	std::string commandName = stringToLower(cmdWithArgs.at(0));
	
	std::map <std::string, int> mapping;

	mapping["pass"] = PASS;
	mapping["nick"] = NICK;
	mapping["user"] = USER;
	mapping["privmsg"] = PRIVMSG;

	// switch (mapping[commandName]) {
	// 	case PASS:
	// 		Pass p = Pass();
	// 		break;
	// 	case NICK:
	// 		Nick n = Nick();
	// 		break;
	// 	case USER:
	// 		User u = User();
	// 		break;
	// 	case PRIVMSG:
	// 		Privmsg p = Privmsg();
	// 		break;
	// }
}

std::string Message::stringToLower(std::string &str) {
	char array[str.length()];

	for (size_t i = 0; i < str.length(); ++i) {
		array[i] = std::tolower(str.at(i));
	}
	std::string ret = std::string(array);
	return ret;
}