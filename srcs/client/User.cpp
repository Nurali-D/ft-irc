#include "User.hpp"

User::User(int fd, struct sockaddr_in address) {
	this->fd = fd;
	this->address = address;
	this->state = LOGGING;
	this->readedMsg = "";
	this->type = "human";
}

User::~User() {
	delete msgHandler;
}

void					User::setNickname(std::string nickname) {
	this->nickname = nickname;
}

void					User::setMsgHandler(MessageHandler *msgHandler) {
	this->msgHandler = msgHandler;
}

void					User::setType(std::string type) {
	this->type = type;
}

MessageHandler			*User::getMsgHandler() {
	return msgHandler;
}

void					User::appendMessage(std::string message) {
	this->messages.push(message);
}

void					User::appendChannel(Channel *channel) {
	this->joinedChannels.push_back(channel);
}

const std::string		&User::getNickname() {
	return (this->nickname);
}

const std::string		&User::getUsername() {
	return (this->username);
}

const std::string		User::getAddress() {
	// get real address !!!
	const std::string address = "127.0.0.1";
	return (address);
}

const std::string		&User::getHostname() {
	return (this->hostname);
}

const User::UserState	&User::getState() {
	return (this->state);
}

std::queue<std::string>	&User::getMessages() {
	return (this->messages);
}

int						User::getFd() {
	return fd;
}

std::string				User::getType() {
	return type;
}

void					User::setState(User::UserState state) {
	this->state = state;
}

void					User::setUsername(std::string username) {
	this->username = username;
}

bool	User::isNickAndUsername() {
	return (!this->nickname.empty() && !this->username.empty());
}

bool	User::isOperator(std::string channelName) {
	std::vector<Channel*>::iterator it;
	for (it = joinedChannels.begin(); it != joinedChannels.end(); ++it) {
		if ((*it)->getName() == channelName && (*it)->getChannelOperator()->getNickname() == nickname)
			return true;
	}
	return false;
}

std::vector<Channel*>	&User::getJoinedChannels() {
	return (joinedChannels);
}
