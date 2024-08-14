NAME =	bankaccount
CPP =	c++
FLAGS =	-Wall -Wextra -Werror -g -std=c++98
RM =	rm -rf

SRCS =	Account.cpp	\
		test.cpp	\
		
OBJS = $(SRCS:.cpp=.o)

.c.o:
	@$(CPP) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(FLAGS) -o $(NAME) $(OBJS)
                                                        
clean:
	@$(RM) $(OBJS) $(NAME)

fclean: clean
	@$(RM) $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re

