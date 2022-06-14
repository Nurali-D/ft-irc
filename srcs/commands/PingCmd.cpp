#include "PingCmd.hpp"


// MARK: - Class Constructor

PingCmd::PingCmd(std::vector<std::string> &args, User *user) : Command(PING, args, user) {}


// MARK: - Class Distructor

PingCmd::~PingCmd(void) {}


// MARK: - Class Methods

void PingCmd::execute() {
	std::string message = "PONG ";
	if (args.size() == 3) {
		message += args.at(1);
	} else if (args.size() == 4) {
		message += args.at(2);
	}
	user->appendMessage(message);
}