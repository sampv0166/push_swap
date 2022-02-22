/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:23:58 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/22 10:27:19 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_a_is_sorted(t_stack *stack_a, t_info *info)
{
	t_list	*temp_list;
	int		f;
	int		j;

	j = 0;
	f = 0;
	temp_list = stack_a->f_element;
	while (temp_list)
	{
		if (temp_list->next && temp_list->num > temp_list->next->num)
		{
			f = 1;
			break ;
		}
		temp_list = temp_list->next;
		j++;
	}
	if (f == 1)
		info->sorted = 0;
	else
		info->sorted = 1;
}

static void	iniit(int *ret, int *i, int *j)
{
	*ret = 1;
	*i = 0;
	*j = 0;
}

int	check_for_doubles(t_info *info, int argc)
{
	int	ret;
	int	i;
	int	j;

	iniit(&ret, &i, &j);
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (info->sorted_arr[i] == info->sorted_arr[j])
			{
				ret = 0;
				return (ret);
			}
			j++;
		}
		i++;
	}
	return (ret);
}

int	verify_input(int argc, t_info *info)
{
	int	ret;

	ret = 1;
	if (!check_for_doubles(info, argc))
		ret = 0;
	return (ret);
}

void	error_check(t_info *info, t_stack *stack_a, t_stack *stack_b)
{
	if (info->length == 0)
		error(info, stack_a, stack_b);
	if (info->length == 1)
	{
		free_all(info, stack_a, stack_b);
		exit(0);
	}		
	if (sort_to_array(info, info->length) == 1)
		error(info, stack_a, stack_b);
	if (!verify_input(info->length, info))
		error(info, stack_a, stack_b);
	create_list(info, stack_a, stack_b);
	stack_a_is_sorted(stack_a, info);
	if (info->sorted)
	{
		free_all(info, stack_a, stack_b);
		exit(0);
	}	
}
