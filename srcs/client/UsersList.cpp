#include "UsersList.hpp"


// MARK: - Class Constructor

UsersList::UsersList(void) {}


// MARK: - Class Distructor

UsersList::~UsersList(void) {}


// MARK: - Class Methods

void	UsersList::addUser(User *user) {
	users.push_back(user);
}

void	UsersList::removeUser(std::string nickname) {
	std::vector<User*>::iterator it;
	for (it = users.begin(); it != users.end(); ++it) {
		if ((*it)->getNickname() == nickname) {
			delete (*it);
			users.erase(it);
		}
	}
}

User	*UsersList::getUser(std::string nickname) {
	std::vector<User*>::iterator it;
	for (it = users.begin(); it != users.end(); ++it) {
		if ((*it)->getNickname() == nickname)
			return (*it);
	}
	return (NULL);
}
