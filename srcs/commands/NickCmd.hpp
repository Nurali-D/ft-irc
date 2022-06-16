#ifndef NICKCMD_HPP
#define NICKCMD_HPP

#include "../headers/libraryHeaders.hpp"
#include "Command.hpp"


class NickCmd : public Command
{
	public:
		NickCmd(std::vector<std::string> &args, User *user);
		~NickCmd(void);

		void execute(void);
};

#endif
