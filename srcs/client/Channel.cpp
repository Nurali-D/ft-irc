#include "Channel.hpp"

Channel::Channel(User *userCreator, std::string channelName) {
	channelOperator = userCreator;
	name = channelName;
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
