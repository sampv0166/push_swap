#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/*
** =============================================================================
** Type Definitions
** =============================================================================
*/

typedef struct s_list
{
	int			     num;
	struct s_list	*next;
}		       t_list;

typedef struct s_sorted
{
	int		*sorted;
	int		middle;
	int 	length;
}

				t_sorted;
typedef struct s_stack
{
	t_list	*f_element;
	int *partitions;
	int count;
	int max;
	int min;
}				t_stack;	

typedef struct s_booleans
{
	int sorted;
	int b_top;
}			   t_booleans;

/*
** =============================================================================
** List Functions
** =============================================================================
*/
t_list	*ft_lstnew(int num);
void	ft_lstadd_back(t_list *lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

/*
** =============================================================================
** Operation Functions
** =============================================================================
*/
void	swap(t_stack *stack, char *op);
void 	push(t_stack *stack1, t_stack *stack2, char *op);
void	rotate(t_stack *stack, char *op);	
void	reverse_rotate(t_stack *stack,  char *op);
void	print_operation(char *op);

/*
** =============================================================================
** Usefull functions
** =============================================================================
*/
size_t  ft_strlen(const char *str);
int     ft_atoi(const char *str);
int		ft_isdigit(int val);

void	quickSort(int array[], int low, int high);
/*
** =============================================================================
** Validating functions
** =============================================================================
*/
int verify_input(int argc, char **argv, t_sorted *sort);


/*
** =============================================================================
** Functions for sorting
** =============================================================================
*/
void sort_2_nums(t_stack *stack_a);
void sort_3_nums(t_stack *stack_a);
void sort_5_nums(t_stack *stack_a, t_stack *stack_b, t_sorted *sort);
void sort_others(t_stack *stack_a, t_stack *stack_b, t_sorted *sort);
int partition_stack_a(t_stack *stack_a, t_stack *stack_b);
/*
** =============================================================================
** Functions To Remove
** =============================================================================
*/
void	print_stack(t_list *list);
void	print_array(int *ar, int argc);

// *IMPORTANT
// ? SHOUD I DO THIS ?
// ! WARNING, DONT DO IT

#endif
