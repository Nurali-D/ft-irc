#include "ChannelsList.hpp"


// MARK: - Class Constructor

ChannelsList::ChannelsList(void) {}


// MARK: - Class Distructor

ChannelsList::~ChannelsList(void) {}


// MARK: - Class Methods

void	ChannelsList::addChannel(User *userCreator, std::string channelName) {
	Channel *newChannel = new Channel(userCreator, channelName);
	userCreator->appendChannel(newChannel);
	channels.push_back(newChannel);
}

void	ChannelsList::removeChannel(std::string channelName) {
	std::vector<Channel*>::iterator it;
	for (it = channels.begin(); it != channels.end(); ++it) {
		if ((*it)->getName() == channelName) {
			delete *it;
			channels.erase(it);
		}
	}
}

Channel	*ChannelsList::getChannel(std::string channelName) {
	std::vector<Channel*>::iterator it;
	for (it = channels.begin(); it != channels.end(); ++it) {
		if ((*it)->getName() == channelName)
			return (*it);
	}
	return (NULL);
}

void	ChannelsList::eraseNullUsers(void) {
	std::vector<Channel*>::iterator it;
	for (it = channels.begin(); it != channels.end(); ++it)
		(*it)->eraseNullUsers();
}
