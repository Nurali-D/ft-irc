#ifndef PRIVMSG_HPP
#define PRIVMSG_HPP

#include "../headers/libraryHeaders.hpp"
#include "Command.hpp"

class PrivmsgCmd : public Command
{
	public:
		PrivmsgCmd(std::vector<std::string> &args, User *user);
		~PrivmsgCmd(void);

		void execute(void);
};

#endif
