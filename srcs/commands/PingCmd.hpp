#ifndef PING_HPP
#define PING_HPP

#include "Command.hpp"
#include "../headers/rpl_codes.hpp"


class PingCmd : public Command
{
	public:
		PingCmd(std::vector<std::string> &args, User *user);
		~PingCmd(void);

		void execute();
};


#endif