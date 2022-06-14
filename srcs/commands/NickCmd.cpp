#include "NickCmd.hpp"


// MARK: - Class Constructor

NickCmd::NickCmd(std::vector<std::string> &args, User *user) : Command(NICK, args, user) {}


// MARK: - Class Distructor

NickCmd::~NickCmd(void) {}


// MARK: - Class Methods

void	NickCmd::execute() {
	if (args.size() != 3)
		return ;							// note: найти код ошибки для неправильного количества аргументов
	
	user->setNickname(args.at(1));
	if (user->getState() == User::AUTH && user->isNickAndUsername()) {
		user->appendMessage(":server " + std::string(RPL_WELCOME) + " "
		+ user->getNickname() + " :Welcome to the Internet Relay Network "
		+ user->getNickname() + "!" + user->getHostname() + "@" + user->getAddress());
	}
}
