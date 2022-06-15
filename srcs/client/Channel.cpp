#include "Channel.hpp"

Channel::Channel(User *userCreator, std::string channelName) {
	channelOperator = userCreator;
	name = channelName;
	addUser(userCreator);
}

Channel::~Channel() {}

std::string	Channel::getName() const {
	return name;
}

std::vector<User*>	&Channel::getUsers() {
	return users;
}

User	*Channel::getChannelOperator() {
	return channelOperator;
}

void	Channel::setChannelOperator() {
	channelOperator = users.front();
}

void	Channel::addUser(User *newUser) {
	users.push_back(newUser);
}

void	Channel::eraseNullUsers(void) {
	std::vector<User*>::iterator it;
	for (it = users.begin(); it != users.end(); ++it) {
		if (!(*it))
			users.erase(it);
	}
}

void	Channel::mailing(std::string msg, User *fromUser) {
	std::vector<User*>::iterator it;
	for (it = users.begin(); it != users.end(); ++it) {
		if ((*it)->getNickname() == fromUser->getNickname())
			continue;
		(*it)->appendMessage(msg);
	}
}
