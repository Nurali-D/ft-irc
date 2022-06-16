#include "BotCmd.hpp"
#include <algorithm>


// MARK: - Class Constructor

BotCmd::BotCmd(std::vector<std::string> &args, User *user) : Command(BOT, args, user) {}


// MARK: - Class Distructor

BotCmd::~BotCmd(void) {}


// MARK: - Class Methods

void BotCmd::execute() {
	msgToBot = user->getNickname();

	for (size_t i = 0; i < args.size() - 1; ++i) {
		msgToBot += " " + args.at(i);
	}
	User *bot = usersList->findBot();
	bot->appendMessage(msgToBot);
}
