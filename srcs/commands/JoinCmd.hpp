#ifndef JOINCMD_HPP
#define JOINCMD_HPP

#include "../headers/libraryHeaders.hpp"
#include "Command.hpp"

class JoinCmd : public Command
{
	public:
		JoinCmd(std::vector<std::string> &args, User *user);
		~JoinCmd(void);

		void execute(void);
	
	private:
		void 		addCreateMessage();
		void 		addJoinMessage();
		std::string	getChannelUsers(std::string &channelName);
};

#endif
