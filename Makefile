SRCS = push_swap.c ft_atoi.c list_functions.c \
		   operations.c validation.c quick_sort.c \
		   ft_isdigit.c sort.c print_stack.c ft_strlen.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CLAFGS = -Wall -Werror -Wextra

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS)
	      $(CC) $(CLAFGS) $(OBJS) -o $(NAME)

clean :	
		rm -rf $(OBJS)
		rm -rf $(NAME)

fclean : clean

re	   : flcean all