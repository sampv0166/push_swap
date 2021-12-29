#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

//Typedefintions

typedef struct s_list
{
	int			     num;
	struct s_list	*next;
}		       t_list;


typedef struct s_stack
{
	t_list	*f_element;
	int max;
	int min;
	int count;
}				t_stack;		

// List functions
t_list	*ft_lstnew(int num);
void	ft_lstadd_back(t_list *lst, t_list *new);
void	swap(t_stack *stack);

// useful functions
size_t  ft_strlen(const char *str);
int     ft_atoi(const char *str);
void	print_stack(t_list *list);


#endif
