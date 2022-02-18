/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:22:59 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/16 14:26:10 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size_of_unsorted_list(t_stack *stack, t_info *info)
{
	t_list	*temp_list;
	int		size;

	temp_list = stack->f_element;
	size = 0;
	while (temp_list)
	{
		temp_list = temp_list->next;
		size++;
	}
	return (size);
}

int	find_median(t_stack *stack, t_info *info, int size, t_stack *stack_b)
{
	t_list	*temp_list;
	int		s;
	int		median;
	int		*numbers;

	numbers = malloc (sizeof (int) * size);
	if (!numbers)
		error(info, stack, stack_b);
	s = 0;
	temp_list = stack->f_element;
	while (s < size)
	{
		numbers[s] = temp_list->num;
		temp_list = temp_list->next;
		s++;
	}
	quicksort(numbers, 0, s - 1);
	median = numbers[s / 2];
<<<<<<< HEAD
	free(numbers);
=======
	if (numbers)
		free(numbers);
>>>>>>> c33d9c62dcd67a37ce7674e6b66d2dee632ee061
	return (median);
}

void	divide_stack_a(t_stack *stack_a, t_stack *stack_b, t_info *info, \
					int size)
{
	int	median;
	int	i;

	i = 0;
	median = find_median(stack_a, info, size, stack_b);
	while (i < size)
	{
		if (stack_a->f_element && stack_a->f_element->num <= median)
			push(stack_a, stack_b, "pb");
		else
			rotate(stack_a, "ra");
		i++;
	}
}

void	sort_stack_a(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int	size;

	size = get_size_of_unsorted_list(stack_a, info);
	if (size > 3)
	{
		divide_stack_a(stack_a, stack_b, info, size);
	}
	else
	{
		if (size == 3)
			sort_3_nums(stack_a);
		if (size == 2)
			sort_2_nums(stack_a);
	}
}
