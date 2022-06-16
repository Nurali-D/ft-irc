#ifndef QUITCMD_HPP
#define QUITCMD_HPP

#include "../headers/libraryHeaders.hpp"
#include "Command.hpp"


class QuitCmd : public Command
{
	public:
		QuitCmd(std::vector<std::string> &args, User *user);
		~QuitCmd(void);

		void execute(void);
};

#endif
