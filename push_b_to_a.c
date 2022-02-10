/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:23:06 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/09 22:23:08 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rotation_instructions(t_info *info, int num, t_stack *stack_a, \
									t_stack *stack_b)
{
	if (info->a_ra_count)
	{
		while (info->a_ra_count)
		{
			if (info->b_rb_count)
			{
				info->b_rb_count--;
				info->a_ra_count = info->a_ra_count - 1;
				rr(stack_a, stack_b);
			}
			else
			{
				rotate(stack_a, "ra");
				info->a_ra_count = info->a_ra_count - 1;
			}
		}
	}
	if (info->b_rb_count)
	{
		while (info->b_rb_count)
		{
			rotate(stack_b, "rb");
			info->b_rb_count = info->b_rb_count - 1;
		}
	}
}

void	execute_rev_rotation_instructions(t_info *info, int num, \
								t_stack *stack_a, t_stack *stack_b)
{
	if (info->a_rra_count)
	{
		while (info->a_rra_count)
		{
			if (info->b_rrb_count)
			{
				info->b_rrb_count--;
				info->a_rra_count = info->a_rra_count - 1;
				rrr(stack_a, stack_b);
			}
			else
			{
				reverse_rotate(stack_a, "rra");
				info->a_rra_count = info->a_rra_count - 1;
			}
		}
	}
	if (info->b_rrb_count)
	{
		while (info->b_rrb_count)
		{
			reverse_rotate(stack_b, "rrb");
			info->b_rrb_count = info->b_rrb_count - 1;
		}
	}
}

void	init_temp_info(t_info *temp_info)
{
	temp_info->instr = 0;
	temp_info->a_rra_count = 0;
	temp_info->a_ra_count = 0;
	temp_info->b_rrb_count = 0;
	temp_info->b_rb_count = 0;
	temp_info->number_to_push = 0;
}

void	store_instructions(t_info *info, t_info *temp_info, t_list *temp_b)
{
	info->instr = temp_info->instr ;
	info->a_rra_count = temp_info->a_rra_count ;
	info->a_ra_count = temp_info->a_ra_count ;
	info->b_rrb_count = temp_info->b_rrb_count;
	info->b_rb_count = temp_info->b_rb_count;
	info->number_to_push = temp_b->num;
}

void	find_minimum_instruction(t_stack *stack_a, t_stack *stack_b, \
							t_info *info, int *num)
{
	t_info	temp_info;
	t_list	*temp_b;

	temp_b = stack_b->f_element;
	info->instr = 2147483648;
	while (temp_b)
	{
		init_temp_info(&temp_info);
		temp_info.number_to_push = find_next_number_in_stack_a(stack_a, \
							temp_b->num, info, stack_a);
		find_number_of_moves_stack_a(stack_a, temp_info.number_to_push \
									, stack_b, &temp_info);
		find_number_of_moves_stack_b(stack_b, &temp_info, temp_b);
		temp_info.instr = temp_info.a_ra_count + temp_info.a_rra_count + \
		temp_info.b_rb_count + temp_info.b_rrb_count;
		if (info->instr > temp_info.instr)
		{
			store_instructions(info, &temp_info, temp_b);
			*num = temp_info.number_to_push;
		}
		temp_b = temp_b->next;
	}
}
