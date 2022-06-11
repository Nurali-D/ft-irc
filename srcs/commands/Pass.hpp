#ifndef PASS_HPP
#define PASS_HPP

#include "Command.hpp"

class PassCmd : public Command
{
	public:
		PassCmd(const Command::CmdType &cmd, const std::map<std::string, std::string> &args, User *user);
		~PassCmd(void);

		void execute();
}


#endif
