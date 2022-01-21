/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@42.abudhabi.ae>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:40:28 by apila-va          #+#    #+#             */
/*   Updated: 2021/10/18 01:34:17 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list		*position;

	position = lst;
	if (!lst || !new)
		return ;
	if (position == NULL)
	{
		lst = new;
	}
	else
	{
		while (position->next != NULL)
		{
			position = position->next;
		}
		position->next = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		new->next = NULL;
		*lst = new;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

t_list	*ft_lstnew(int num)
{
	t_list	*new;

	new = malloc(sizeof (t_list));
	if (new == NULL)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}