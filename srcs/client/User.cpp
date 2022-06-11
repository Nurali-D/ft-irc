#include "User.hpp"

User::User(int fd, struct sockaddr_in address) {
	this->fd = fd;
	this->address = address;
}

User::~User() {}

void					User::setNickname(std::string nickname) {
	this->nickname = nickname;
}



void					User::appendMessage(std::string message) {
	this->messages.push(message);
}

std::string				User::getNickname() {
	return nickname;
}



std::stack<std::string>	&User::getMessages() {
	return messages;
}

