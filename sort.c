/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:23:40 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/10 01:15:13 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_nums(t_stack *stack_a)
{
	if (stack_a->f_element->num > stack_a->f_element->next->num)
	{
		swap(stack_a, "sa");
	}
}

void	sort_3_nums(t_stack *stack_a)
{
	if ((stack_a->f_element->num > stack_a->f_element->next->num) && \
		(stack_a->f_element->num > stack_a->f_element->next->next->num))
	{
		rotate(stack_a, "ra");
	}
	else if ((stack_a->f_element->next->num > \
		stack_a->f_element->next->next->num) && \
		(stack_a->f_element->next->num > stack_a->f_element->num))
	{
		reverse_rotate(stack_a, "rra");
	}
	if (stack_a->f_element->num > stack_a->f_element->next->num)
		swap(stack_a, "sa");
}

int	sort_to_array(t_info *info, int argc)
{
	int	i;
	int	j;
	int	atoi_check;

	info->sorted_arr = (int *) malloc(sizeof(int) * (argc));
	info->not_sorted_arr = (int *) malloc(sizeof(int) * (argc));
	if (!info->sorted_arr || !info->not_sorted_arr)
		return (1);
	i = 0;
	j = 0;
	while (i < argc && (info->argmnts + i) && ft_strlen(info->argmnts[i]) > 0)
	{
		atoi_check = 0;
		info->sorted_arr[j] = ft_atoi(info->argmnts[i], &atoi_check);
		info->not_sorted_arr[j] = ft_atoi(info->argmnts[i], &atoi_check);
		if (atoi_check == 1)
			return (1);
		i++;
		j++;
	}
	quicksort(info->sorted_arr, 0, argc - 1);
	return (0);
}

void	fix_stack(int *ra_count, int *rra_count, t_stack *stack_a)
{
	int	i;

	i = 0;
	if (*ra_count <= *rra_count)
	{
		while (i < *ra_count)
		{
			rotate(stack_a, "ra");
			i++;
		}
	}
	else
	{
		while (i < *rra_count)
		{
			reverse_rotate(stack_a, "rra");
			i++;
		}
	}
}

void	re_arrange_stack(t_stack *stack_a, int nextnumber)
{
	t_list	*stack_ra;
	t_list	*stack_rra;
	int		ra_count;
	int		rra_count;

	ra_count = 0;
	rra_count = 0;
	stack_ra = stack_a->f_element;
	stack_rra = stack_a->f_element;
	while (stack_ra && stack_ra->num != nextnumber)
	{
		stack_ra = stack_ra->next;
		ra_count++;
	}
	while (stack_ra != NULL)
	{
		stack_ra = stack_ra->next;
		rra_count++;
	}
	fix_stack(&ra_count, &rra_count, stack_a);
}
