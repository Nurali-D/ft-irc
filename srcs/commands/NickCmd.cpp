#include "NickCmd.hpp"


// MARK: - Class Constructor

NickCmd::NickCmd(std::vector<std::string> &args, User *user) : Command(NICK, args, user) {}


// MARK: - Class Distructor

NickCmd::~NickCmd(void) {}


// MARK: - Class Methods

void	NickCmd::execute() {
	if (args.size() == 2) {
		user->appendMessage(":server " + std::string(ERR_NONICKNAMEGIVEN) + " " + user->getNickname()
			+ " : No nickname given");
		return ;
	}
	if (args.size() != 3)
		return ;
	
	std::string nickname = args.at(1);
	if (usersList->isUsedNickname(nickname)) {
		user->appendMessage(":server " + std::string(ERR_NICKNAMEINUSE) + " " + user->getNickname()
			+ " : Nickname is already in use");
		return ;
	}

	user->setNickname(nickname);
	if (user->getState() == User::AUTH && user->isNickAndUsername())
		addWelcomeMessage();
}
