#ifndef TOPICCMD_HPP
#define TOPICCMD_HPP

#include "../headers/libraryHeaders.hpp"
#include "Command.hpp"


class TopicCmd : public Command
{
	public:
		TopicCmd(std::vector<std::string> &args, User *user);
		~TopicCmd(void);

		void execute(void);
};

#endif
