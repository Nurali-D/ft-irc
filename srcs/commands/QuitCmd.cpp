#include "QuitCmd.hpp"


// MARK: - Class Constructor

QuitCmd::QuitCmd(std::vector<std::string> &args, User *user) : Command(QUIT, args, user) {}


// MARK: - Class Distructor

QuitCmd::~QuitCmd(void) {}


// MARK: - Class Methods

void	QuitCmd::execute(void) {
	if (args.size() > 3)
		return ;
	
	std::string msg = "disconnect";

	if (args.size() == 3)
		msg = args.at(1);

	std::vector<Channel*> channels = user->getJoinedChannels();
	std::vector<Channel*>::iterator it;
	for (it = channels.begin(); it != channels.end(); ++it) {
		(*it)->mailing(":" + user->getNickname() + "!" + user->getUsername() + "@" + user->getAddress() + " QUIT :" + msg, user);
	}
	user->setState(User::DEACTIVE);
}
