/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 04:55:07 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/16 08:08:12 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	invalid_op(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

void	rrr_bonus(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, "");
	reverse_rotate(stack_b, "");
}

void	ss_bonus(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, "");
	swap(stack_b, "");
}

void	rr_bonus(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, "");
	rotate(stack_b, "");
}

void	execute_oprations(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strcmp(str, "rra"))
		reverse_rotate(stack_a, "");
	else if (!ft_strcmp(str, "rrb"))
		reverse_rotate(stack_b, "");
	else if (!ft_strcmp(str, "rrr"))
		rrr_bonus(stack_a, stack_b);
	else if (!ft_strcmp(str, "sa"))
		swap(stack_a, "");
	else if (!ft_strcmp(str, "sb"))
		swap(stack_b, "");
	else if (!ft_strcmp(str, "ss"))
		ss_bonus(stack_a, stack_b);
	else if (!ft_strcmp(str, "pa"))
		push(stack_b, stack_a, "");
	else if (!ft_strcmp(str, "pb"))
		push(stack_a, stack_b, "");
	else if (!ft_strcmp(str, "ra"))
		rotate(stack_a, "");
	else if (!ft_strcmp(str, "rb"))
		rotate(stack_b, "");
	else if (!ft_strcmp(str, "rr"))
		rr_bonus(stack_a, stack_b);
	else
		invalid_op();
}
