#ifndef PASS_HPP
#define PASS_HPP

#include "Command.hpp"
#include "../headers/rpl_codes.hpp"

// ARGS: {"pass": "value", "server_pass": "value"}

class PassCmd : public Command
{
	public:
		PassCmd(const std::map<std::string, std::string> &args, User *user);
		~PassCmd(void);

		void execute();
};


#endif
