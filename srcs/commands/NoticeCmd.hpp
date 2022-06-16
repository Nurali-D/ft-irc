#ifndef NOTICECMD_HPP
#define NOTICECMD_HPP

#include "../headers/libraryHeaders.hpp"
#include "Command.hpp"


class NoticeCmd : public Command
{
	public:
		NoticeCmd(std::vector<std::string> &args, User *user);
		~NoticeCmd(void);

		void execute(void);
};

#endif
