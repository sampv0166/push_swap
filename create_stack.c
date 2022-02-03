#include "push_swap.h"

static void create_list(int *argc, char **argv, t_stack *stack)
{
    int i;
    int j;
  
    t_list *temp_list;
    t_list *stack_a;
    stack_a = ft_lstnew(ft_atoi(argv[1]));
    i = 2;
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
    while(argv[i])
        i++;
    *argc = i + 1;    
    stack_a = ft_lstnew(ft_atoi(argv[0]));

    i = 1;
    while(i < *argc - 1) 
    {
        temp_list = ft_lstnew(ft_atoi(argv[i]));
        ft_lstadd_back(stack_a, temp_list);
        i++;
    }
    stack->count = *argc - 1;
    stack->f_element = stack_a;
}

void create_stack(int *argc, char **argv, t_stack *stack_a, t_sorted *sort)
{
    char **split_args;

    split_args = NULL;
    if(*argc == 2)
    {
        split_args = ft_split(argv[1], ' ');
        printf("sss ====%s====\n", split_args[0]);
        sort_to_array(sort, argc, split_args);
        verify_input(*argc,split_args,sort);
        create_list_from_single_argument(argc, split_args, stack_a);
    }
    else
    {
        sort_to_array(sort, argc, argv); 
        verify_input(*argc,argv,sort);
        create_list(argc, argv, stack_a);
    }
}