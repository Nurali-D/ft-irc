#include "BotCmd.hpp"


// MARK: - Class Constructor

BotCmd::BotCmd(std::vector<std::string> &args, User *user) : Command(BOT, args, user) {}


// MARK: - Class Distructor

BotCmd::~BotCmd(void) {}


// MARK: - Class Methods

void BotCmd::execute() {
	
}