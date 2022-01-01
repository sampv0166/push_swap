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
		i++;
	}
	return (ret);
}

int verify_int_limit(t_sorted *sort)
{
	
}

int verify_input(int argc, char **argv, t_sorted *sort)
{
	int ret;

	ret = 1;
	ret = verify_numbers(argc, argv);
	ret = verify_int_limit(sort);

	return (ret);
}