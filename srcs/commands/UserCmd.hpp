#ifndef USERCMD_HPP
#define USERCMD_HPP

#include "../headers/libraryHeaders.hpp"
#include "Command.hpp"

// ARGS: {"username": "value", "hostname": "value", "servername": "value", "realname": "value"}

class UserCmd : public Command
{
	public:
		UserCmd(std::map<std::string, std::string> &args, User *user);
		~UserCmd(void);

		void execute();
};

#endif
