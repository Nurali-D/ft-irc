#ifndef NICK_HPP
#define NICK_HPP

#include "../headers/libraryHeaders.hpp"
#include "Command.hpp"

// ARGS: {"nickname": "value"}

class NickCmd : public Command
{
	public:
		NickCmd(const std::map<std::string, std::string> &args, User *user);
		~NickCmd(void);

		void execute();
};

#endif
