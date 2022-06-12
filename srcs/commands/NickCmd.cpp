#include "NickCmd.hpp"

// MARK: - Class Constructor

NickCmd::NickCmd(std::map<std::string, std::string> &args, User *user) : Command(NICK, args, user) {}


// MARK: - Class Distructor

NickCmd::~NickCmd(void) {}


// MARK: - Class Methods

void	NickCmd::execute()
{
	if (args.find("nickname") != args.end()) {
		std::cout << args["nickname"] << std::endl;
		user->setNickname(args["nickname"]);
		if (user->getState() == User::AUTH && user->isNickAndHostname()) {
			user->appendMessage(":server " + std::string(RPL_WELCOME) + " "
			+ user->getNickname() + " :Welcome to the Internet Relay Network "
			+ user->getNickname() + "!" + user->getHostname() + "@" + user->getAddress());
		}
	} else {
		std::cout << "not found" << std::endl;
	}
}
