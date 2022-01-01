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

typedef struct s_sorted
{
	int		*sorted;
	int		middle;
}				t_sorted;

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
void 	push(t_stack *stack1, t_stack *stack2);

// useful functions
size_t  ft_strlen(const char *str);
int     ft_atoi(const char *str);
void	print_stack(t_list *list);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	rotate(t_stack *stack);	
void	reverse_rotate(t_stack *stack);

void	quickSort(int array[], int low, int high);

int verify_input(int argc, char **argv, t_sorted *sort);

// other fuctions
int	ft_isdigit(int val);

#endif
