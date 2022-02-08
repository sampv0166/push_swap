#include "push_swap.h"

static void create_list(int *argc, char **argv, t_stack *stack, t_sorted *sort, t_stack *stack_b)
{
    int i;
    int j;
    int atoi_check;
  
    atoi_check = 0;
    t_list *temp_list;
    t_list *stack_a;
    stack_a = ft_lstnew(ft_atoi(argv[1], &atoi_check));
    if(atoi_check == 1)
        error(sort, argv, stack, stack_b);
    i = 2;
    while(i < (*argc))
    {
        atoi_check = 0;
        temp_list = ft_lstnew(ft_atoi(argv[i], &atoi_check));
        ft_lstadd_back(stack_a, temp_list);
            stack->f_element = stack_a;
        if(atoi_check == 1)
             error(sort, argv, stack, stack_b);
        i++;
    }
    stack->count = (*argc) - 1;
    stack->f_element = stack_a;
}

static void create_list_from_single_argument(int *argc, char **argv, t_stack *stack, t_sorted *sort, t_stack *stack_b)
{
    int i;
    int j;
    t_list *temp_list;
    t_list *stack_a;
    int atoi_check;

    i = 0;
    while(argv[i])
        i++;
    *argc = i;
    atoi_check = 0;    
    stack_a = ft_lstnew(ft_atoi(argv[0],&atoi_check));
    if(atoi_check == 1)
         error(sort, argv, stack, stack_b);
    i = 1;
    while(i < *argc) 
    {
        atoi_check = 0;
        temp_list = ft_lstnew(ft_atoi(argv[i], &atoi_check));
        ft_lstadd_back(stack_a, temp_list);
            stack->f_element = stack_a;
        if(atoi_check == 1)
             error(sort, argv, stack, stack_b);
        i++;
    }
    stack->count = *argc;
    stack->f_element = stack_a;
}

void sort_to_array_2(t_sorted *sort, int *argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
    int i;
    int j;
    int atoi_check;

    sort->sorted = (int *) malloc(sizeof(int) * (*argc));
    if(!sort->sorted)
         error(sort, argv, stack_a, stack_b);
    i = 0;
    j = 0;
    while(i < (*argc))
    {
        atoi_check = 0;
        sort->sorted[j] = ft_atoi(argv[i], &atoi_check);
        if(atoi_check == 1)
             error(sort, argv, stack_a, stack_b);
        i++;
        j++;
    }
    quickSort(sort->sorted, 0, *argc - 1);
    sort->length = (*argc) - 1;
}

void create_stack(int *argc, char **argv, t_stack *stack_a, t_sorted *sort, t_stack *stack_b)
{
    char **split_args;
    int i;
    
    i = 0;
    split_args = NULL;

    if(*argc == 2)
    {
        sort->split_flag = 1;
        split_args = ft_split(argv[1], ' ');
         *argc = *argc + 1;  
        if(!split_args)
             error(sort, argv, stack_a, stack_b);
        create_list_from_single_argument(argc, split_args, stack_a, sort, stack_b);
        sort_to_array_2(sort, argc, split_args,stack_a, stack_b);
        if(!verify_input(*argc, split_args, sort,stack_a, stack_b))
             error(sort, split_args, stack_a, stack_b);
        while (split_args[i])
        {
            if (split_args[i])
                free(split_args[i]);
            i++;
        }
        if (split_args)
            free(split_args); 
    }
    else
    {
        int i;
        int j;

        j = 0;
        i =1;
        while(argv[i])
        {
            j = 0;
            while(argv[i][j])
            {
                if(!(argv[i][j] >= '0' && argv[i][j] <= '9'))
                    error(sort, argv, stack_a, stack_b) ;
                j++;
            }
            i++;
        }
        create_list(argc, argv, stack_a, sort, stack_b);
        sort_to_array(sort, argc, argv, stack_a, stack_b); 
        if(!verify_input(*argc, argv, sort,stack_a, stack_b))
            error(sort, argv, stack_a, stack_b);  
    }
}