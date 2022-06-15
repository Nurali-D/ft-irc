#include "KickCmd.hpp"


// MARK: - Class Constructor

KickCmd::KickCmd(std::vector<std::string> &args, User *user) : Command(KICK, args, user) {}


// MARK: - Class Distructor

KickCmd::~KickCmd(void) {}


// MARK: - Class Methods

void KickCmd::execute(void) {
	if (args.size() != 5)
		return ;
	
	
}
