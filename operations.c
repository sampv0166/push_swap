/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 04:19:07 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/16 14:20:02 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char *op)
{
	t_list	*first;
	t_list	*second;
	int		tmp_num;

	if (stack->count <= 1)
		return ;
	else
	{
		first = stack->f_element;
		second = first->next;
		tmp_num = first->num;
		first->num = second->num;
		second->num = tmp_num;
	}
	print_operation(op);
}

void	link_element(t_stack *stack1, t_stack *stack2)
{
	stack2->f_element = stack1->f_element;
	stack1->f_element = stack1->f_element->next;
	stack2->f_element->next = NULL;
	stack2->count = stack2->count + 1;
	if (stack1->count != 0)
		stack1->count = stack1->count - 1;
}

void	push(t_stack *stack1, t_stack *stack2, char *op)
{
	t_list	*temp_elem;

	if (stack1->count <= 0)
		return ;
	if (!stack2->f_element)
	{	
		link_element(stack1, stack2);
		print_operation(op);
		return ;
	}
	temp_elem = ft_lstnew(stack1->f_element->num);
	ft_lstadd_front(&stack2->f_element, temp_elem);
	temp_elem = stack1->f_element->next;
	if (stack1->f_element)
		free(stack1->f_element);
	stack1->f_element = temp_elem;
	if (stack1->count != 0)
		stack1->count = stack1->count - 1;
	stack2->count = stack2->count + 1;
	print_operation(op);
}

void	rotate(t_stack *stack, char *op)
{
	t_list	*temp_elem;

	if (stack->count <= 1)
		return ;
	temp_elem = stack->f_element;
	stack->f_element = stack->f_element->next;
	temp_elem->next = NULL;
	ft_lstadd_back(stack->f_element, temp_elem);
	print_operation(op);
}

//resetting felement to temp

void	reverse_rotate(t_stack *stack, char *op)
{
	t_list	*temp_elem;
	t_list	*temp;

	temp = stack->f_element;
	if (stack->count <= 1)
		return ;
	if (stack->count > 2)
	{
		while (stack->f_element->next->next != NULL)
		{
			temp_elem = stack->f_element->next->next;
			stack->f_element = stack->f_element->next;
		}
	}
	else
	{
		temp_elem = stack->f_element->next;
	}		
	stack->f_element->next = NULL;
	stack->f_element = temp;
	ft_lstadd_front(&stack->f_element, temp_elem);
	print_operation(op);
}
