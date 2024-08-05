NAME = megaphone
CPP = c++
FLAGS = -Wall -Wextra -Werror -g -std=c++98
RM = rm -rf
SRCS = megaphone.cpp

OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CXXFLAGS) -o $(NAME) $(OBJS)
                                                        
clean:
	@$(RM) $(OBJS) $(NAME)

fclean: clean
	@$(RM) $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re