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
	fromUser->appendMessage("Parsed " + msgToParse);
}