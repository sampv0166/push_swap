#include "push_swap.h"

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

static void sort_to_array(t_sorted *sort, int argc, char **argv)
{
    int i;
    int j;

    sort->sorted = (int *) malloc (sizeof(int) * argc);
    i = 1;
    j = 0;
    while(i < argc)
    {
        sort->sorted[j] = ft_atoi(argv[i]);
        i++;
        j++;
    }
    argv[i] = NULL;
    quickSort(sort->sorted, 0, argc - 2);
    sort->middle = sort->sorted[(argc - 1) / 2];
}

static void create_list(int argc, char **argv, t_stack *stack)
{
    int i;
    int j;

    t_list *temp_list;
    t_list *stack_a;

    stack_a = ft_lstnew(ft_atoi(argv[1]));
    i = 2;
    while(i < argc)
    {
        temp_list = ft_lstnew(ft_atoi(argv[i]));
        ft_lstadd_back(stack_a, temp_list);
        i++;
    }
    stack->count = argc - 1;
    stack->f_element = stack_a;
}

int main (int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    t_sorted sort;
    sort_to_array(&sort, argc, argv);
    verify_input(argc, argv, &sort);
    create_list(argc, argv, &stack_a); 
    stack_b.f_element = NULL;
    printf("stack A \n");
    print_stack(stack_a.f_element);
    printf("stack B \n");
    print_stack(stack_b.f_element);
    printf("sorted array\n");
    print_array(sort.sorted, argc); 
    // int num;
    // int i;

    // i = 0;
    // num = 0;
    // while(i <= stack_a.count)
    // {
        
    //     num = stack_a.f_element->num;
    //     if(num <= sort.middle)
    //     {
    //         push(&stack_a, &stack_b);     
    //     }
    //     else
    //     {
    //         rotate(&stack_a);
    //         i++; 
    //     }
    // }
    // printf("middle : %d", sort.middle);

    

    return (0);
}