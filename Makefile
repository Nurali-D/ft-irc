NAME = ircserv

CC = c++

# FLAGS = -g -fsanitize=address -Wall -Werror -Wextra -std=c++98
OS = $(shell uname)
CFLAGS = -g -I/usr/include/kqueue -Wall -Werror -Wextra -std=c++98 
# LDFLAGS = $(if $(filter-out Linux,$(OS)),$(),$(-lkqueue))
ifeq ($(OS), Linux)
	LDFLAGS = -lkqueue
else
	LDFLAGS =
endif

SRCS = srcs/main.cpp \
	srcs/server/ServerSocket.cpp \
	srcs/server/ServerEngine.cpp \
	srcs/client/Channel.cpp \
	srcs/client/User.cpp \
	srcs/client/MessageHandler.cpp \
	srcs/client/UsersList.cpp \
	srcs/client/ChannelsList.cpp \
	srcs/commands/Command.cpp \
	srcs/commands/PassCmd.cpp \
	srcs/commands/NickCmd.cpp \
	srcs/commands/UserCmd.cpp \
	srcs/commands/PrivmsgCmd.cpp \
	srcs/commands/JoinCmd.cpp \
	srcs/commands/PingCmd.cpp \
	srcs/commands/KickCmd.cpp \
	srcs/commands/NoticeCmd.cpp \
	srcs/commands/TopicCmd.cpp \
<<<<<<< HEAD
	srcs/commands/QuitCmd.cpp \
	srcs/commands/WhoCmd.cpp
=======
	srcs/commands/BotCmd.cpp
>>>>>>> 1fb2c91342cbfe20478bdd961d3acfaa04be0917

OBJS = $(SRCS:.cpp=.o)

DEPS = $(SRCS:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC)  $^ -o  $@ $(LDFLAGS)
	

%.o: %.cpp Makefile
	$(CC) $(CFLAGS) -MMD -MP -c  $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
