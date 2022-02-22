/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:20:26 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/22 11:14:35 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b_4nums(t_stack *stack_a, t_stack \
		*stack_b, int max, int max2)
{
	if (stack_a->f_element->num == max || stack_a->f_element->num == max2)
		push(stack_a, stack_b, "pb");
	else if (stack_a->f_element->next->num == max || \
			stack_a->f_element->next->num == max2)
	{
		rotate(stack_a, "ra");
		push(stack_a, stack_b, "pb");
	}
	else if (stack_a->f_element->next->next->num == max || \
			stack_a->f_element->next->next->num == max2)
	{
		reverse_rotate(stack_a, "rra");
		reverse_rotate(stack_a, "rra");
		push (stack_a, stack_b, "pb");
	}
	else if (stack_a->f_element->next->next->next->num == max || \
			stack_a->f_element->next->next->next->num == max2)
	{
		reverse_rotate(stack_a, "rra");
		push (stack_a, stack_b, "pb");
	}
}

void	do_ops(t_stack *a, t_stack *b, int i)
{
	if (i == 1)
	{
		reverse_rotate(a, "rra");
		reverse_rotate(a, "rra");
		push (a, b, "pb");
	}
	if (i == 2)
	{
		rotate(a, "ra");
		rotate(a, "ra");
		push (a, a, "pb");
	}
}

void	push_to_b_5nums(t_stack *a, t_stack *b, int max, int max2)
{
	if (a->f_element->num == max || a->f_element->num == max2)
		push(a, b, "pb");
	else if (a->f_element->next->num == max || a->f_element->next->num == max2)
	{
		rotate(a, "ra");
		push(a, b, "pb");
	}
	else if (a->f_element->next->next->next->next->num \
		== max || a->f_element->next->next->next->next->num == max2)
	{
		reverse_rotate(a, "rra");
		push (a, b, "pb");
	}
	else if (a->f_element->next->next->next->num == max || \
			a->f_element->next->next->next->num == max2)
	{
		do_ops (a, b, 1);
	}
	else if (a->f_element->next->next->num == max || \
			a->f_element->next->next->num == max2)
	{
		do_ops (a, b, 2);
	}
}

int	*q_sort(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	t_list	*temp_list;
	int		s;
	int		*numbers;

	numbers = malloc (sizeof (int) * 5);
	if (!numbers)
		error(info, stack_a, stack_b);
	s = 0;
	temp_list = stack_a->f_element;
	while (s < 5)
	{
		numbers[s] = temp_list->num;
		temp_list = temp_list->next;
		s++;
	}
	quicksort(numbers, 0, 4);
	return (numbers);
}

void	sort_5_nums(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int		max;
	int		max2;
	int		*numbers;

	numbers = q_sort (stack_a, stack_b, info);
	max = numbers[0];
	max2 = numbers[1];
	free (numbers);
	push_to_b_5nums(stack_a, stack_b, max, max2);
	push_to_b_4nums(stack_a, stack_b, max, max2);
	sort_3_nums(stack_a);
	if (stack_b->f_element->num < stack_b->f_element->next->num)
		swap(stack_b, "sb");
	push(stack_b, stack_a, "pa");
	push(stack_b, stack_a, "pa");
}
