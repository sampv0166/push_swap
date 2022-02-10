SRCS = push_swap.c ft_atoi.c list_functions.c \
		   operations.c validation.c quick_sort.c \
		sort.c ft_split.c split_helper_functions.c \
		helper_functions.c push_a_to_b.c push_b_to_a.c \
		simul_operations.c sort_helper_functions.c split_join.c

BNS_SRCS = checker.c ft_atoi.c list_functions.c \
		   operations.c validation.c quick_sort.c \
		sort.c ft_split.c split_helper_functions.c \
		helper_functions.c push_a_to_b.c push_b_to_a.c \
		simul_operations.c sort_helper_functions.c split_join.c \
		get_next_line.c get_next_line_utils.c 

OBJS = $(SRCS:.c=.o)

BNS_OBJS = $(BNS_SRCS:.c=.o)

CC = gcc

CLAFGS = -Wall -Werror -Wextra

NAME = push_swap

BNS_NAME = checker

all : $(NAME)

bonus : $(BNS_NAME)

$(BNS_NAME) : $(BNS_OBJS)
	      $(CC) $(CLAFGS) $(BNS_OBJS) -o $(BNS_NAME) 

$(NAME) : $(OBJS)
	      $(CC) $(CLAFGS) $(OBJS) -o $(NAME) 

clean :	
		rm -rf $(OBJS)
		rm -rf $(BNS_OBJS)
		
fclean : clean
		 rm -rf $(NAME)
		 rm -rf $(BNS_NAME)

re	   : flcean all bonus