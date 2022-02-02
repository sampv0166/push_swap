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
	int 	length;
}

				t_sorted;
typedef struct s_stack
{
	t_list	*f_element;
	int 	count;
}				t_stack;	

typedef struct s_info
{
	long instr;
	int sorted;
	int flag;
	int a_rra_count;
	int a_ra_count;
	int b_rrb_count;
	int b_rb_count;
	int number_to_push;
}			   t_info;

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
void rr(t_stack *stack_a, t_stack *stack_b);
void rrr(t_stack *stack_a, t_stack *stack_b);	

/*
** =============================================================================
** Usefull functions
** =============================================================================
*/
size_t  ft_strlen(const char *str);
int     ft_atoi(const char *str);
int		ft_isdigit(int val);
char	**ft_split(char const *s, char c);
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
void sort_5_nums(t_stack *stack_a, t_stack *stack_b, t_sorted *sort, t_info *info);
void sort_the_rest(t_stack *stack_a, t_stack *stack_b, t_info *info);
int find_median(t_stack *stack,t_info *info ,int size);
int find_next_number_in_stack_a(t_stack *stack_a, int number, t_info *info, t_stack *stack_b);
void find_number_of_moves_stack_a(t_stack *stack_a, int num ,t_stack *stack_b, t_info *info);
void find_number_of_moves_stack_b(t_stack *stack_b,t_info *temp_info,t_list *temp_b);
void find_minimum_instruction(t_stack *stack_a, t_stack *stack_b, t_info *info, int *num);
void re_arrange_stack(t_stack *stack_a, int nextnumber);
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
