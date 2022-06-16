#ifndef BOTCMD_HPP
#define BOTCMD_HPP

#include "Command.hpp"
#include "../headers/rpl_codes.hpp"


class BotCmd : public Command
{
	public:
		BotCmd(std::vector<std::string> &args, User *user);
		~BotCmd(void);

		void execute();
};


#endif