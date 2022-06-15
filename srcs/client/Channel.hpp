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
		User				*getUser(std::string nickname);
		User				*getChannelOperator();
		void				setChannelOperator();
		void				addUser(User *newUser);
		bool				removeUser(std::string nickname);
		bool				isMember(std::string nickname);
		void				eraseNullUsers(void);
		void				mailing(std::string msg, User *fromUser);

};

#endif