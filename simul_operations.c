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