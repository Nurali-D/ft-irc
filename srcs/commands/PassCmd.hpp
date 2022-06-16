#ifndef PASSCMD_HPP
#define PASSCMD_HPP

#include "Command.hpp"
#include "../headers/rpl_codes.hpp"


class PassCmd : public Command
{
	public:
		PassCmd(std::vector<std::string> &args, User *user);
		~PassCmd(void);

		void execute();
};


#endif
