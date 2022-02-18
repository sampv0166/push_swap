/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 00:52:12 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/16 09:45:52 by apila-va         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
		{
			return (*s1 - *s2);
		}
	}
	return (*s1 - *s2);
}

static	void	get_operations(t_info *info, t_stack \
			*stack_a, t_stack *stack_b)
{
	char	*str;
	int		i;

	str = get_next_line(0);
	while (str)
	{
		i = 0;
		while (str[i] != '\n')
			i++;
		str[i] = '\0';
		execute_oprations(str, stack_a, stack_b);
		free(str);
		str = get_next_line(0);
	}
	if (str)
		free (str);
}

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_info		info;

	if (argc == 1)
		return (0);
	if (argc >= 2)
	{
		initialize_stacks(&stack_a, &stack_b, &info);
		info.argmnts = split_and_join(argc, argv);
		if (info.argmnts)
			info.length = count_args_after_joining(info.argmnts);
		error_check(&info, &stack_a, &stack_b);
		get_operations(&info, &stack_a, &stack_b);
		stack_a_is_sorted(&stack_a, &info);
		if (info.sorted)
			write(1, "OK", 2);
		else
			write(1, "KO", 2);
		free_all(&info, &stack_a, &stack_b);
	}
}
