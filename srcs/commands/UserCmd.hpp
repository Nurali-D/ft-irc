#ifndef USERCMD_HPP
#define USERCMD_HPP

#include "../headers/libraryHeaders.hpp"
#include "Command.hpp"


class UserCmd : public Command
{
	public:
		UserCmd(std::vector<std::string> &args, User *user);
		~UserCmd(void);

		void execute();
};

#endif
