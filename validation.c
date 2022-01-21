#include "push_swap.h"

int verify_numbers(int argc, char **argv)
{
	int i;
	int ret;

	i = 1;
	ret = 1;
	while(argv[i])
	{
		long k;
		k = ft_atoi(argv[i]);
		if(k > 2147483647 || k < -2147483648)
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
		j = i + 1;
		while(j < argc - 1)
		{
			if(sort->sorted[i] == sort->sorted[j])
				ret = 0;
			j++;
		}
		i++;
	}
	sort->length = argc;
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

