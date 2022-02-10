/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:26:10 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/10 04:08:33 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_args_after_joining(char **arg)
{
	int	i;

	i = 0;
	while (arg[i] && ft_strlen(arg[i]) > 0)
		i++;
	return (i);
}

static char	*ft_strjoin(char *saved_line, char *buffer)
{
	char	*new_string;
	int		total_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	total_len = ft_strlen(saved_line) + ft_strlen(buffer) + 2;
	new_string = (char *) malloc(sizeof(char) * (total_len));
	if (new_string == NULL)
		return (NULL);
	while (saved_line[i])
		new_string[i++] = saved_line[j++];
	j = 0;
	while (buffer[j])
		new_string[i++] = buffer[j++];
	new_string[i++] = ' ';
	new_string[i] = '\0';
	if (saved_line)
		free(saved_line);
	return (new_string);
}

char	*join_args(char **argv)
{
	int		i;
	char	*join;
	char	*temp;

	join = malloc (sizeof (char) * 1);
	temp = join;
	if (!join)
		return (NULL);
	i = 1;
	while (argv[i])
	{
		join = ft_strjoin(join, argv[i]);
		i++;
	}
	// if (join == NULL)
	// {
	// 	free(join);
	// 	return (join);
	// }
	// else
	// {
	// 	free(join);
	// }
	return (join);
}

char	**split_and_join(int argc, char **argv)
{
	char	*joined_args;
	char	**split_args;
	int		i;

	i = 0;
	joined_args = join_args(argv);
	if (!joined_args)
		return (NULL);
	split_args = ft_split(joined_args, ' ');
	i = 0;
	return (split_args);
}
