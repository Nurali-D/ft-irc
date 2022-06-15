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

User	*Channel::getUser(std::string nickname) {
	std::vector<User*>::iterator it;
	for (it = users.begin(); it != users.end(); ++it) {
		if ((*it)->getNickname() == nickname)
			return (*it);
	}
	return (NULL);
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

bool	Channel::removeUser(std::string nickname) {
	std::vector<User*>::iterator it;
	for (it = users.begin(); it != users.end(); ++it) {
		if ((*it)->getNickname() == nickname)
			users.erase(it);
			return true;
	}
	return false;
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
		if (fromUser && (*it)->getNickname() == fromUser->getNickname())
			continue;
		(*it)->appendMessage(msg);
	}
}

bool	Channel::isMember(std::string nickname) {
	std::vector<User*>::iterator it;
	for (it = users.begin(); it != users.end(); ++it) {
		if ((*it)->getNickname() == nickname)
			return true;
	}
	return false;
}
