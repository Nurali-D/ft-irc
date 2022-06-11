#ifndef PASS_HPP
#define PASS_HPP

#include "Command.hpp"

// ARGS: {"pass": "", "server_pass": ""}

class PassCmd : public Command
{
	public:
		PassCmd(const std::map<std::string, std::string> &args, User *user);
		~PassCmd(void);

		void execute();
};


#endif
