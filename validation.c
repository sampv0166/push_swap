#include "push_swap.h"

void stack_a_is_sorted(t_stack *stack_a, t_info *info)
{
    t_list *temp_list;
    int f;
    int j;

    j = 0;
    f = 0;
    temp_list = stack_a->f_element;
    while(temp_list)
    {
        if(temp_list->next && temp_list->num  > temp_list->next->num)
        {
            f = 1;
            break ;
        }
        temp_list = temp_list->next;  
        j++;
    }
    if(f == 1)
        info->sorted = 0;   
    else    
        info->sorted = 1;
}

int verify_numbers(int argc, char **argv, t_sorted *sort, t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int ret;
	int atoi_check;

	i = 1;
	ret = 1;
	
	while(argv[i])
	{
		long k;
		atoi_check = 0;
		k = ft_atoi(argv[i], &atoi_check);
		if(atoi_check == 1)
			 error(sort, argv, stack_a, stack_b);
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
	printf("%d",argc);
	while(i < argc - 1)
	{
		j = i + 1;
		if(sort->sorted[i] == sort->sorted[j])
		{
			ret = 0;
			return (ret);
		}
		while(j < argc - 1)
		{
			if(sort->sorted[i] == sort->sorted[j])
			{
				ret = 0;
				return (ret);
			}
			j++;
		}
		i++;
	}
	sort->length = argc;
	return(ret);
}

int verify_input(int argc, char **argv, t_sorted *sort, t_stack *stack_a, t_stack *stack_b)
{
	int ret;

	ret = 1;
	if (!verify_numbers(argc, argv, sort, stack_a, stack_b) || !check_for_doubles(sort, argc))
		ret = 0;
	return (ret);
}

