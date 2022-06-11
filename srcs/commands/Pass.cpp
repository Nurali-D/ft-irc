#include "Pass.hpp"


// MARK: - Class Constructor

PassCmd::PassCmd(const std::map<std::string, std::string> &args, User *user) : Command(Command::PASS, args, user) {}


// MARK: - Class Distructor

PassCmd::~PassCmd(void) {}


// MARK: - Class Methods

void PassCmd::execute()
{
	if (args["pass"] && args["pass"] == args["server_pass"])
		user->setState(User::ACTIVE);
}
