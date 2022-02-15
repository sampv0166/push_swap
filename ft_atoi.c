/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:22:27 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/09 22:22:31 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(size_t *i, size_t *s, size_t *res)
{
	*i = 0;
	*s = 1;
	*res = 0;
}

void	skip_sapces_and_signs(const char *str, size_t *i, size_t *s)
{
	while (str && str[(*i)] == ' ' || str[(*i)] == '\n' || str[(*i)] == '\t' || \
		str[(*i)] == '\v' || str[(*i)] == '\f' || str[(*i)] == '\r')
		(*i)++;
	if (str && str[(*i)] == '-' || str[(*i)] == '+')
	{
		if (str[(*i)] == '-')
			*s = -1;
		(*i)++;
	}
}

int	exit_atoi(int *atoi_chec)
{
	*atoi_chec = 1;
	return (*atoi_chec);
}

int	ft_atoi(const char *str, int *atoi_check)
{
	size_t	i;
	size_t	s;
	size_t	res;

	init(&i, &s, &res);
	if (ft_strlen(str) == 1 && (*str == '-' || *str == '+'))
		return (exit_atoi(atoi_check));
	skip_sapces_and_signs(str, &i, &s);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
		if ((res > 2147483647 && s == 1) || (res > 2147483648 && s == -1))
			return (exit_atoi(atoi_check));
	}
	if (str[i] != '\0')
		return (exit_atoi(atoi_check));
	return (res * s);
}
