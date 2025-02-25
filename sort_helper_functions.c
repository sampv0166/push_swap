/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:02:27 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/22 10:25:42 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_number_of_moves_stack_a(t_stack *stack_a, \
			int nextnumber, t_stack *stack_b, t_info *temp_info)
{
	t_list	*stack_ra;
	int		ra_count;
	int		rra_count;

	ra_count = 0;
	rra_count = 0;
	stack_ra = stack_a->f_element;
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
	if (ra_count <= rra_count)
		temp_info->a_ra_count = ra_count;
	else
		temp_info->a_rra_count = rra_count;
}

void	find_number_of_moves_stack_b(t_stack *stack_b,
					t_info *temp_info, t_list *temp_b)
{
	t_list	*stack_rb;
	int		rb_count;
	int		rrb_count;

	rb_count = 0;
	rrb_count = 0;
	stack_rb = stack_b->f_element;
	while (stack_rb && stack_rb->num != temp_b->num)
	{
		stack_rb = stack_rb->next;
		rb_count++;
	}
	while (stack_rb != NULL)
	{
		stack_rb = stack_rb->next;
		rrb_count++;
	}
	if (rb_count <= rrb_count)
		temp_info->b_rb_count = rb_count;
	else
		temp_info->b_rrb_count = rrb_count;
}

void	find_min_diff(t_vals *vars, t_list *list, int number)
{
	while (list != NULL)
	{
		vars->current_list_num = list->num;
		vars->temp_min = number - vars->current_list_num ;
		if (vars->temp_min < 0)
			vars->temp_min = vars->temp_min * -1;
		if (vars->min > vars->temp_min)
		{
			vars->min = number - vars->current_list_num;
			if (vars->min < 0)
				vars->min = vars->min * -1;
			vars->nearest_num = list->num;
		}
		list = list->next;
	}
}

int	find_next_number_in_stack_a(t_stack *stack_a, \
						int number, t_info *info, t_stack *stack_b)
{
	t_list	*list;
	t_vals	vars;

	vars.min = __LONG_LONG_MAX__;
	vars.temp_min = __LONG_LONG_MAX__;
	list = stack_a->f_element;
	vars.nearest_num = list->num;
	find_min_diff(&vars, list, number);
	return (vars.nearest_num);
}
