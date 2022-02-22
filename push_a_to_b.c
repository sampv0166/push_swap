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
	median = numbers[(s / 2)];
	if (numbers)
		free(numbers);
	return (median);
}

int check_if_rotation_needed(t_list *list, int num)
{
	t_list *lst;

	lst = list;
	while(lst)
	{
		if(lst->num <= num)
			return (1);
		lst = lst->next;	
	}
	return (0);
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
		{
			if(check_if_rotation_needed(stack_a->f_element, median))
				rotate(stack_a, "ra");	
		}
		// int ra_count;
		// int rra_count;
		// ra_count = 0;
		// rra_count = 0;

		// t_list *list;

		// list = stack_a->f_element;
		// while (list)
		// {
		// 	if(list->num <= median)
		// 		break ;
		// 	ra_count++;
		// 	list = list->next;
		// }
		// while(list != NULL)
		// {
		// 	list = list->next;
		// 	rra_count++;
		// }

		// if(ra_count <= rra_count)
		// {
		// 	while (ra_count)
		// 	{
		// 		rotate (stack_a, "ra");
		// 		ra_count--;
		// 	}
		// }
		// else
		// {
		// 	while(rra_count)
		// 	{
		// 		reverse_rotate (stack_a, "rra");
		// 		rra_count--;
		// 	}
		// }
		// push (stack_a, stack_b, "pb");
		i++;
	}
}

void	sort_stack_a(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int	size;
	int i;

	size = get_size_of_unsorted_list(stack_a, info);
	if(size > 5 && size <= 14)
	{
		//printf("\nsize=%d\n",size);
		//print_stack(stack_a->f_element);
	
		i = size;
		while (i)
		{
			if (i == 5) 
				break ;
			push(stack_a, stack_b, "pb");
			i--;
		}
		size = i;
		//print_stack(stack_a->f_element);
	}
	else if (size > 5)
	{
		divide_stack_a(stack_a, stack_b, info, size);
	}

	if (size == 5)
	{
		
		sort_5_nums(stack_a, stack_b, info);
		//print_stack(stack_a->f_element);
		//exit (0);
		// if (size == 5)
		// 	sort_5_nums(stack_a, stack_b, info);
		// if (size == 4)
		// 	sort_4_nums(stack_a, stack_b, info);		
		// if (size == 3)
		// 	sort_3_nums(stack_a);
		// if (size == 2)
		// 	sort_2_nums(stack_a);
	}
}
