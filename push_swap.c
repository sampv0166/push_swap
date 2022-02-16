/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:23:12 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/16 10:45:18 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_list(t_info *info, t_stack *stack, t_stack *stack_b)
{
	int		i;
	int		j;
	t_list	*temp_list;
	t_list	*stack_a;

	stack_a = ft_lstnew(info->not_sorted_arr[0]);
	i = 1;
	while (i < info->length)
	{
		temp_list = ft_lstnew(info->not_sorted_arr[i]);
		ft_lstadd_back(stack_a, temp_list);
		stack->f_element = stack_a;
		i++;
	}
	stack->count = info->length;
	stack->f_element = stack_a;
}

void	initialize_stacks(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	info->argmnts = NULL;
	stack_b->f_element = NULL;
	stack_a->f_element = NULL;
	info->sorted = 0;
	info->instr = __INT_MAX__;
	stack_a->count = 0;
	stack_b->count = 0;
	info->length = 0;
	info->allocated = 0;
}

void	push_to_a(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int	num;

	num = 0;
	find_minimum_instruction(stack_a, stack_b, info, &num);
	if (info->number_to_push > num)
		info->a_ra_count = info->a_ra_count + 1;
	execute_rotation_instructions(info, num, stack_a, stack_b);
	execute_rev_rotation_instructions(info, num, stack_a, stack_b);
	push (stack_b, stack_a, "pa");
}

void	sort_the_rest(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int	i;

	i = 0;
	while (i == 0)
	{
		stack_a_is_sorted(stack_a, info);
		if (!info->sorted)
			sort_stack_a(stack_a, stack_b, info);
		else if (stack_b->f_element != NULL)
		{
			while (stack_b->f_element)
			{
				push_to_a(stack_a, stack_b, info);
				i = 1;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_info		info;

	if (argc == 1)
		exit(0);
	initialize_stacks(&stack_a, &stack_b, &info);
	info.argmnts = split_and_join(argc, argv);
	if (info.argmnts)
		info.length = count_args_after_joining(info.argmnts);
	if (info.length == 1 || info.length == 0)
	{
		free_all(&info, &stack_a, &stack_b);
		exit(0);
	}
	error_check(&info, &stack_a, &stack_b);
	if (info.length == 2)
		sort_2_nums(&stack_a);
	else if (info.length == 3)
		sort_3_nums(&stack_a);
	else
		sort_the_rest(&stack_a, &stack_b, &info);
	re_arrange_stack(&stack_a, info.sorted_arr[0]);
	free_all(&info, &stack_a, &stack_b);
	exit (0);
}
