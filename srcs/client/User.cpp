#include "User.hpp"

User::User(int fd, struct sockaddr_in address) {
	this->fd = fd;
	this->address = address;
	this->state = LOGGING;
}

User::~User() {}

void					User::setNickname(std::string nickname) {
	this->nickname = nickname;
}

void					User::setMsgHandler(MessageHandler *msgHandler) {
	this->msgHandler = msgHandler;
}

MessageHandler			*User::getMsgHandler() {
	return msgHandler;
}

void					User::appendMessage(std::string message) {
	this->messages.push(message);
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

std::stack<std::string>	&User::getMessages() {
	return (this->messages);
}

void					User::setState(User::UserState state)
{
	this->state = state;
}

void					User::setUsername(std::string username)
{
	this->username = username;
}

bool	User::isNickAndHostname()
{
	return (!this->nickname.empty() && !this->username.empty());
}
