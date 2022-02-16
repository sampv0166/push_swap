/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:22:39 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/16 10:34:03 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_count(char const *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
		}
		else if (s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				i++;
			}
			j++;
		}
	}
	return (j);
}

static char	**ft_create_string(char **ptr, char const *s, char c, size_t len)
{
	size_t	i;
	size_t	array_index;

	i = 0 ;
	array_index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				i++;
				len++;
			}
			ptr[array_index++] = ft_substr(s, i - len, len);
			len = 0;
		}
		else
			i++;
	}
	ptr[array_index] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	first_array_length;
	size_t	string_length;

	string_length = 0;
	if (!s)
	{
		free ((char *) s);
		s = NULL;
		return (0);
	}
	first_array_length = ft_count(s, c);
	ptr = (char **)ft_calloc(sizeof (char *), first_array_length + 1);
	if (ptr == NULL)
		return (ptr);
	if (first_array_length <= 0)
	{
		ptr[0] = NULL;
		return (ptr);
	}
	ptr = ft_create_string(ptr, s, c, string_length);
	return (ptr);
}
