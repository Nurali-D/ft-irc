#include "NamesCmd.hpp"


// MARK: - Class Constructor

NamesCmd::NamesCmd(std::vector<std::string> &args, User *user) : Command(NAMES, args, user) {}


// MARK: - Class Distructor

NamesCmd::~NamesCmd(void) {}


// MARK: - Class Methdos

void	NamesCmd::execute(void) {
	if (user->getState() != User::ACTIVE)
		return ;

	if (args.size() == 2) {
		std::vector<User*> users = usersList->getUsers();
		std::vector<Channel*> channels = channelsList->getChannels();

		std::vector<Channel*>::iterator it;
		for (it = channels.begin(); it != channels.end(); ++it) {
			std::vector<User*> channelUsers = (*it)->getUsers();
			std::vector<User*>::iterator cu_it;
			std::string usersString;
			for (cu_it = channelUsers.begin(); cu_it != channelUsers.end(); ++cu_it){
				usersString += (*cu_it)->getNickname();
				if (cu_it + 1 != channelUsers.end())
					usersString += " ";
			}
			user->appendMessage(":server " + std::string(RPL_NAMREPLY) + " " + user->getNickname() + " Channel " + (*it)->getName() + " : " + usersString);
		}

		std::vector<User*>::iterator u_it;
		std::string usersString;
		for (u_it = users.begin(); u_it != users.end(); ++u_it) {
			if ((*u_it)->getJoinedChannels().empty()) {
				usersString += (*u_it)->getNickname();
				if (u_it + 1 != users.end())
					usersString += " ";
			}
		}
		user->appendMessage(":server " + std::string(RPL_NAMREPLY) + " " + user->getNickname()  + " : " + usersString);
		user->appendMessage(":server " + std::string(RPL_ENDOFNAMES) + " " + user->getNickname()  + " :End of /NAMES list");

	} else {

		std::string channelTarget = args.at(1);
		Channel *channel = channelsList->getChannel(channelTarget);
		if (channel) {
			std::vector<User*> channelUsers = channel->getUsers();
			std::vector<User*>::iterator cu_it;
			std::string usersString;
			for (cu_it = channelUsers.begin(); cu_it != channelUsers.end(); ++cu_it){
				usersString += (*cu_it)->getNickname();
				if (cu_it + 1 != channelUsers.end())
					usersString += " ";
			}
			user->appendMessage(":server " + std::string(RPL_NAMREPLY) + " " + user->getNickname() + " Channel " + channel->getName() + " : " + usersString);
			user->appendMessage(":server " + std::string(RPL_ENDOFNAMES) + " " + user->getNickname() + " " + channelTarget + " :End of /NAMES list");
		} else {
			user->appendMessage(":server " + std::string(ERR_NOSUCHCHANNEL) + " " + user->getNickname()  + " " + channelTarget 
				+ ": No such channel!");
		}
	}
}
