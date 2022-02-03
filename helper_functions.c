#include "push_swap.h"

int	ft_isdigit(int val)
{
	if (val >= '0' && val <= '9')
	{
		return (1);
	}
	return (0);
}

size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;;
    while(str && str[i])
    {
        i++;
    }
    return (i);
}

void print_stack(t_list *list)
{
	t_list *temp_list;
	int i;

	i = 0;
	temp_list = list;
	while(temp_list)
    {
		i++;
        printf("%d th element  = %d\n", i, temp_list->num);
	    temp_list =  temp_list->next;	
	}
	printf("\n\n");
}

void print_array(int *ar, int argc)
{
    int i;

    i = 0;
    while(i < argc - 1)
    {
        printf("%d ", ar[i]);
        i++;
    }
    printf("\n");
}

void print_operation(char *op)
{
	if(*op)
	{	
		char c = '\n';
		write(1, op, ft_strlen(op));
		write(1, &c, 1);
	}
}
