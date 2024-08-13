NAME		= phonebook
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm
RMFLAG		= -f
SRC			= Contact PhoneBook main
SRCS		= $(addsuffix .cpp, $(SRC))
OBJS		= $(SRCS:.cpp=.o)

all : $(NAME)

clean :
		$(RM) $(RMFLAG) $(OBJS)

fclean :
		$(RM) $(RMFLAG) $(OBJS) $(NAME)

re : fclean
	$(MAKE) all

%.o : %.cpp
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) -o $@ $^

.PHONY : all clean fclean re 