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
	std::string admin = channelOperator->getNickname();
	for (it = users.begin(); it != users.end(); ++it) {
		if ((*it)->getNickname() == nickname) {
			if (nickname == admin) {
				channelOperator = *(it + 1);
			}
			users.erase(it);
			return true;
		}
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
		std::cout << "member nickname: " << (*it)->getNickname() << " - " + nickname << std::endl;
		if ((*it)->getNickname() == nickname)
			return true;
	}
	std::cout << "false\n";
	return false;
}
