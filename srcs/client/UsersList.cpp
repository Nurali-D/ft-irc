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

void	UsersList::removeNonactiveUsers(int kq) {
	User::UserState deactiveState = User::DEACTIVE;
	User *user = NULL;
	struct kevent evSet[2];

	for (size_t i = 0; i < users.size(); ++i) {
		user = users.at(i);
		if (user->getState() == deactiveState && user->getMessages().empty()) {
			users.erase(users.begin() + i);
			std::cout << "user deleted" << " fd = " << user->getFd() << std::endl;
			EV_SET(&evSet[0], user->getFd(), EVFILT_READ, EV_DELETE, 0, 0, NULL); 
			EV_SET(&evSet[1], user->getFd(), EVFILT_WRITE, EV_DELETE, 0, 0, NULL);
			if (kevent(kq, evSet, 2, NULL, 0, NULL) == -1) {
				std::cerr << "kevent() error 2" << std::endl;
				return ;
			}
			close(user->getFd()); // disconnects user from server
			// deleteUserFromChannels(user); // note: need to modify
			break;
		}
	}
}

size_t	UsersList::size() const {
	return users.size();
}

User	*UsersList::at(int i) {
	return users.at(i);
}