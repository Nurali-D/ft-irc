#ifndef USERSLIST_HPP
#define USERSLIST_HPP

#include "../headers/libraryHeaders.hpp"

class UsersList;

#include "User.hpp"


class UsersList
{
	private:
		std::vector<User*> users;

	public:
		UsersList(void);
		~UsersList(void);

		void	addUser(User *user);
		void	removeUser(std::string nickname);
		void	removeNonactiveUsers(int kq);
		User	*getUser(std::string nickname);
};

#endif
