#ifndef NAMESCMD_HPP
#define NAMESCMD_HPP

#include "../headers/libraryHeaders.hpp"
#include "Command.hpp"


class NamesCmd : public Command
{
	public:
		NamesCmd(std::vector<std::string> &args, User *user);
		~NamesCmd(void);

		void execute(void);
};


#endif
