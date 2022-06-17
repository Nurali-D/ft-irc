#ifndef LISTCMD_HPP
#define LISTCMD_HPP

#include "../headers/libraryHeaders.hpp"
#include "Command.hpp"


class ListCmd : public Command
{
	public:
		ListCmd(std::vector<std::string> &args, User *user);
		~ListCmd(void);

		void	execute(void);
		std::string itoa(int size);
};


#endif
