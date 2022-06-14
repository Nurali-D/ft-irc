#ifndef JOIN_HPP
#define JOIN_HPP

#include "../headers/libraryHeaders.hpp"
#include "Command.hpp"

class JoinCmd : public Command
{
	public:
		JoinCmd(std::vector<std::string> &args, User *user);
		~JoinCmd(void);

		void execute(void);
};

#endif
