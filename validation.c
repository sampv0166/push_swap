#include "push_swap.h"

int verify_numbers(int argc, char **argv)
{
	int i;
	int j;
	int ret;

	i = 1;
	ret = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if(!ft_isdigit(argv[i][j]))
			{
				ret = 0;
				return (ret);
			}	
			j++;
		}
		if(ft_atoi(argv[i]) > 2,147,483,647 || ft_atoi(argv[i]) < -2147483648)
			return(0);
		i++;
	}
	return (ret);
}

int check_for_doubles(t_sorted *sort, int argc)
{
	int ret;
	int i;
	int j;

	ret = 1;
	i  = 0;
	j = 0;
	while(i < argc - 1)
	{
		j = 0;
		while(j < argc - 1)
		{
			if(sort->sorted[i] == sort->sorted[j])
				ret = 0;
			j++;
		}
		i++;
	}
	return(ret);
}

int verify_input(int argc, char **argv, t_sorted *sort)
{
	int ret;

	ret = 1;
	if (!verify_numbers(argc, argv) || !check_for_doubles(sort, argc))
		ret = 0;
	return (ret);
}

