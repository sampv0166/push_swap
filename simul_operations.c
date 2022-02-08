#include "push_swap.h"

void rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a,"rr");
	rotate(stack_b,"");
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{	
	reverse_rotate(stack_a, "rrr");
	reverse_rotate(stack_b,"");
}

// void free_me(int **ptr)
// {
// 	if(*ptr)
// 	{
// 		free(*ptr);
// 		*ptr = NULL;
// 	}
// }

void error(t_sorted *sort, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int i;
	t_list *temp;

	i = 0;
	// if(sort->length > 0)
	// 	free(sort->sorted);
	while(stack_a->f_element !=  NULL)
	{
		temp = stack_a->f_element;
		free(temp);
		stack_a->f_element = stack_a->f_element->next;
	}
	if(stack_b->f_element)
		free(stack_b->f_element);
	if(sort->split_flag == 1 && argv)
	{
		while (argv[i])
		{
			if (argv[i])
				free(argv[i]);
			i++;
		}
		if (argv)
			free(argv);  
	}
	write(1, "Error\n",6);  		
	exit(0);	
}