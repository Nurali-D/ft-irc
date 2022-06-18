#ifndef FROMBOTCMD_HPP
#define FROMBOTCMD_HPP

#include "Command.hpp"
#include "../headers/rpl_codes.hpp"


class FromBotCmd : public Command
{
	public:
		FromBotCmd(std::vector<std::string> &args, User *user);
		~FromBotCmd(void);

		void execute();

	private:
		std::string msgToBot;
};


#endif