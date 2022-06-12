#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "../headers/libraryHeaders.hpp"


class Channel;

#include "User.hpp"

class Channel
{

	private:
		std::vector<User*>	users;
		User				*channelOperator;
		std::string			name;
		std::string			topik;

	public:
		Channel(User *userCreator, std::string channelName);
		~Channel();

		std::string			getName() const;
		std::vector<User*>	&getUsers();
		User				*getChannelOperator();
		void				setChannelOperator();
		void				addUser(User *newUser);

};

#endif