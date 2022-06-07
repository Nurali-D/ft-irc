NAME = ircserv

CC = c++

# FLAGS = -g -fsanitize=address -Wall -Werror -Wextra -std=c++98
OS = $(uname)
CFLAGS = -g -I/usr/include/kqueue -Wall -Werror -Wextra -std=c++98 
LDFLAGS = $(if $(filter-out Linux,$(OS)),$(),$(-lkqueue))

SRCS = main.cpp ServerSocket.cpp ServerEngine.cpp \

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
