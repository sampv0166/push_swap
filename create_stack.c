#include "push_swap.h"

static void create_list(int *argc, char **argv, t_stack *stack, int i)
{
    int j;
  
    t_list *temp_list;
    t_list *stack_a;
    stack_a = ft_lstnew(ft_atoi(argv[1]));
    while(i < (*argc))
    {
        temp_list = ft_lstnew(ft_atoi(argv[i]));
        ft_lstadd_back(stack_a, temp_list);
        i++;
    }
    stack->count = (*argc) - 1;
    stack->f_element = stack_a;
}


static void create_list_from_single_argument(int *argc, char **argv, t_stack *stack)
{
    int i;
    int j;
    t_list *temp_list;
    t_list *stack_a;

    i = 0;
   
    stack_a = ft_lstnew(ft_atoi(argv[0]));

    i = 1;
    while(i < *argc) 
    {
        temp_list = ft_lstnew(ft_atoi(argv[i]));
        ft_lstadd_back(stack_a, temp_list);
        i++;
    }
    stack->count = *argc;
    stack->f_element = stack_a;
}

void sort_to_array_2(t_sorted *sort, int *argc, char **argv)
{
    int i;
    int j;

    sort->sorted = (int *) malloc (sizeof(int) * (*argc + 1));
    i = 0;
    j = 0;
    while(i < (*argc))
    {
        sort->sorted[j] = ft_atoi(argv[i]);
        i++;
        j++;
    }
    argv[i] = NULL;
    quickSort(sort->sorted, 0, *argc - 1);
    sort->length = (*argc) - 1;
}


void create_stack(int *argc, char **argv, t_stack *stack_a, t_sorted *sort)
{
    char **split_args;
    int i;

    split_args = NULL;
    i = 0;
    if(*argc == 2)
    {
        split_args = ft_split(argv[1], ' ');
        while(split_args[i])
            i++;
        *argc = i + 1; 
        printf("argc ==== %d\n",*argc);
        create_list(argc, argv, stack_a, 1);
        create_list_from_single_argument(argc, split_args, stack_a);
        
        sort_to_array_2(sort, argc, split_args);
        *argc = *argc + 1; 
        if(!verify_input(*argc, split_args, sort))
            exit(0);    
    }
    else
    {
          printf("argc ==== %d\n",*argc);
        create_list(argc, argv, stack_a, 2);
        sort_to_array(sort, argc, argv); 
        if(!verify_input(*argc, argv, sort))
            exit(0);
    }
}