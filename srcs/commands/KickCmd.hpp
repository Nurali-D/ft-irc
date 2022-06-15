#ifndef KICKCMD_HPP
#define KICKCMD_HPP

#include "../headers/libraryHeaders.hpp"
#include "Command.hpp"


class KickCmd : public Command
{
	public:
		KickCmd(std::vector<std::string> &args, User *user);
		~KickCmd(void);

		void execute(void);
};

#endif
