#include "push_swap.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	s;
	size_t	res;

	i = 0;
	s = 1;
	res = 0;
	if(ft_strlen(str) == 1 && (*str == '-' || *str == '+'))
	{
		exit(0);
	}
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || \
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
		if(res > 2147483647)
		{
			exit(0);
		}
	}
	if(str[i] != '\0')
	{
		exit(0);
	}
	return (res * s);
}