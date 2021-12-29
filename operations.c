/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 04:19:07 by apila-va          #+#    #+#             */
/*   Updated: 2021/12/29 05:57:17 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack *stack)
{
	t_list *first;
	t_list *second;
	int tmp_num;
	
	if(stack->count <= 1)
		return ;
	else
	{
		//printf(" \n number : %d", stack->f_element->next->num);
		first = stack->f_element;
		second = first->next;
		tmp_num = first->num;
		printf(" \n number : %d \n", second->num);	
		first->num = second->num;
		second->num = tmp_num;		
	}		
}