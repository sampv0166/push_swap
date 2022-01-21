# include "push_swap.h"

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

