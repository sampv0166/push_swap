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

void initialize_stacks(t_stack *stack_a, t_stack *stack_b, int argc, t_booleans *info)
{
    stack_b->f_element = NULL;
    stack_b->count = 0;

    stack_a->count = 0;
    stack_a->f_element = 0;

    stack_a->partitions = (int *) malloc(sizeof(int) * argc);
    if(!stack_a->partitions)
        exit(1);
    stack_b->partitions = (int *) malloc(sizeof(int ) * argc);
    if(!stack_b->partitions)
        exit(1);
    info->sorted = 0;    

    stack_a->max = 0;
    stack_b->max = 0;
    stack_b->min = 0;
    

}

int get_size_of_unsorted_list_b(t_stack *stack, t_stack *stack_b)
{
    //? WHAT If THE STACK IS EMPTY ???? 
    t_list *temp_list;
    int size;

    temp_list = stack->f_element;
    size = 0;
    //TODO : ALSO CHECK IF WE REACHEDE POSITION WHICH IS ALREADY SORTED
    while(temp_list && temp_list->num != stack->partitions[stack->min - 1])
    {
        temp_list = temp_list->next;
        size++;
    }
    return(size);   
}

void push_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
    int count;

    count = get_size_of_unsorted_list_b(stack_b, stack_a);
    printf("count ========== %d\n", count);

    while(stack_b->f_element->num != stack_b->partitions[stack_b->min - 1])
    {
        if(count == 2)
        {
             
            if(stack_b->f_element->num < stack_b->f_element->next->num)
            {
                swap(stack_b,"sb");
                push(stack_b, stack_a, "pa");
                push(stack_b, stack_a, "pa");
                stack_b->min--;
                stack_a->partitions[0] = stack_a->f_element->num;
                stack_a->partitions[1] = 1;
                break ;
            }
            else
            {
                push(stack_b, stack_a, "pa");
                push(stack_b, stack_a, "pa");
                stack_b->min--;
                stack_a->partitions[0] = stack_a->f_element->num;
                stack_a->partitions[1] = 1;
                break ;
            }
        }
        else
        {
            push(stack_b, stack_a, "pa");
            stack_a->partitions[1] = 0;
        }
    }
    print_stack(stack_a->f_element);
    print_stack(stack_b->f_element);

    printf("ops = %d\n", stack_a->max + stack_b->max);
    // exit(1);
}

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    t_booleans info;
    t_sorted sort;



    initialize_stacks(&stack_a, &stack_b, argc, &info);
    sort_to_array(&sort, argc, argv);
    create_list(argc, argv, &stack_a);
    //TODO :VERIFY INPUT AND CHECK IF THE LIST IS ALREADY SORTED
    // TODO : ALSO CHECK IF STACK IS EMPTY
    while(!info.sorted)
    {
       //info.sorted = check_if_stack_a_is_sorted(stack_a);
            if(partition_stack_a(&stack_a, &stack_b))
            {
                printf("STACK A\n");
                print_stack(stack_a.f_element);
                printf("STACK B\n");
                print_stack(stack_b.f_element);
            }
            else
            {
                push_b_to_a(&stack_a, &stack_b);
            }
            //TODO :CHANGE THE PARTITION VALUE OF STACK A BECAUSE ALL ELEMENTS 
            //*IN STACK A ARE SORTED
            //partition_stack_b(stack_b, stack_a);
    }
}
