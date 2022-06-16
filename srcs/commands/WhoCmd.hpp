#ifndef WHOCMD_HPP
#define WHOCMD_HPP

#include "../headers/libraryHeaders.hpp"
#include "Command.hpp"


class WhoCmd : public Command
{
	public:
		WhoCmd(std::vector<std::string> &args, User *user);
		~WhoCmd(void);

		void execute(void);
};

#endif
