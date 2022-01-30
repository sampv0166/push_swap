#include "push_swap.h"
void initialize_stacks(t_stack *stack_a, t_stack *stack_b, int argc, t_info *info)
{
    stack_b->f_element = NULL;
    stack_a->f_element = 0;
    info->sorted = 0;    
    info->instr = 0;
    info->a_top = 2147483648;
    info->b_top = -1;
    stack_b->p = malloc(sizeof (t_list*) * argc);
    stack_b->p[0] = NULL;
    info->flag = 0;
    stack_a->count = 0;
    stack_b->count = 0;
    stack_b->max = 0;
    stack_a->max = 0;
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
    sort->length = argc - 1;
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

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    t_info info;
    t_sorted sort;
    int i;

    i = 0;
    initialize_stacks(&stack_a, &stack_b, argc, &info);
    sort_to_array(&sort, argc, argv); 
    create_list(argc, argv, &stack_a);

    while(i < sort.length - 1 / 2)
    {
        if(stack_a.f_element->num < sort.sorted[50])
        {
            push(&stack_a, &stack_b, "pb");
        }
        else
        {
            rotate(&stack_a, "ra");
        }
        i++;
    }
    printf("stack a\n");
    print_stack(stack_a.f_element);
    printf("stack b\n");
    print_stack(stack_b.f_element);
    printf("\ntotal instructions : %d", stack_a.max + stack_b.max);
}
