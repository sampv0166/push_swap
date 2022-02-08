SRCS = push_swap.c ft_atoi.c list_functions.c \
		   operations.c validation.c quick_sort.c \
		sort.c ft_split.c split_helper_functions.c \
		helper_functions.c push_a_to_b.c push_b_to_a.c \
		simul_operations.c sort_helper_functions.c create_stack.c

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