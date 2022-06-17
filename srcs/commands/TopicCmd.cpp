#include "TopicCmd.hpp"


// MARK: - Class Contructor

TopicCmd::TopicCmd(std::vector<std::string> &args, User *user) : Command(TOPIC, args, user) {}


// MARK: - Class Destructor

TopicCmd::~TopicCmd(void) {}


// MARK: - Class Methods

void	TopicCmd::execute(void) {
	if (args.size() != 4)
		return ;
	
	std::string channelTarget = args.at(1);
	std::string topic = args.at(2);

	Channel *channel = channelsList->getChannel(channelTarget);
	if (!channel) {
		user->appendMessage(":server " + std::string(ERR_NOSUCHCHANNEL)
		+ " " + user->getNickname() + " : No such channel");
		return ;
	}
	channel->setTopic(topic);
	channel->mailing(":" + user->getNickname() + " TOPIC " + channelTarget + " :" + topic, NULL);
}
