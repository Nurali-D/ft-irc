#include "UserCmd.hpp"


// MARK: - Class Constructor

UserCmd::UserCmd(std::vector<std::string> &args, User *user) : Command(USER, args, user) {}


// MARK: - Class Destructor

UserCmd::~UserCmd(void) {}


// MARK: - Class Methods

void	UserCmd::execute(void) {
	if (args.size() < 2 || args.size() > 6)
		return ;

	user->setUsername(args.at(1));
	if (user->getState() == User::AUTH && user->isNickAndUsername()) {
		addWelcomeMessage();
		user->setState(User::ACTIVE);
	}
}