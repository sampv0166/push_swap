#include "push_swap.h"

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
    sort->length = argc - 1;
    //printf("len = %d\n", sort->length);
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

void initialize_stacks(t_stack *stack_a, t_stack *stack_b)
{
    stack_b->f_element = NULL;
    stack_b->count = 0;
   
    stack_b->min = 0;

    stack_a->count = 0;
     stack_b->max = 0;
    stack_a->max = 0;
    stack_a->min = 0;
    stack_a->f_element = 0;
}

int main (int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    t_sorted sort;

    initialize_stacks(&stack_a, &stack_b);
    sort_to_array(&sort, argc, argv);
    create_list(argc, argv, &stack_a); 

    //  TODO : ALSO CHECK IF THE NUMBERS ARE ALREADY SORTED

    if (verify_input(argc, argv, &sort))
    {
        printf("stack A before sorting \n");
        print_stack(stack_a.f_element);
        if(argc == 3)
        {
            sort_2_nums(&stack_a);
        }
        if(argc == 4)
        {
            sort_3_nums(&stack_a);
        }
        else
        {
            sort_others(&stack_a, &stack_b, &sort);
        }
    }
    else
    {
        exit(0);
    }
    
    // swap(&stack_a, "sa");
    // swap(&stack_b, "sb");
    
    // push(&stack_a, &stack_b, "pb");
    // push(&stack_b, &stack_a, "pa");

    // rotate(&stack_a, "ra");
    // rotate(&stack_b, "rb");

    // reverse_rotate(&stack_a, "rra");
    // reverse_rotate(&stack_b, "rrb");

    printf("\nstack A after sorting \n");
    print_stack(stack_a.f_element);
    // printf("stack B \n");
    // print_stack(stack_b.f_element);
    // printf("sorted array\n");
    // print_array(sort.sorted, argc);


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