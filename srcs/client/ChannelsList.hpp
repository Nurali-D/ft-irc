#ifndef CHANNELSLIST_HPP
#define CHANNELSLIST_HPP

#include "../headers/libraryHeaders.hpp"
#include "Channel.hpp"


class ChannelsList
{
	private:
		std::vector<Channel*> channels;
	
	public:
		ChannelsList(void);
		~ChannelsList(void);

		void	addChannel(User *userCreator, std::string channelName);
		void	removeChannel(std::string channelName);
		Channel	*getChannel(std::string channelName);

		void	eraseNullUsers(void);

};

#endif
