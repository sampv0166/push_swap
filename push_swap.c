#include "push_swap.h"

void initialize_stacks(t_stack *stack_a, t_stack *stack_b,t_info *info)
{
    stack_b->f_element = NULL;
    stack_a->f_element = 0;
    info->sorted = 0;    
    info->instr = __INT_MAX__;
    info->flag = 0;
    stack_a->count = 0;
    stack_b->count = 0;
}

void push_to_a(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
    int num; 

    num = 0;
    find_minimum_instruction(stack_a, stack_b, info, &num);
    if(info->number_to_push > num)
            info->a_ra_count = info->a_ra_count + 1;
    execute_rotation_instructions(info, num, stack_a, stack_b);
    execute_rev_rotation_instructions(info, num, stack_a, stack_b);
}


void sort_the_rest(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
    int i;

    i = 0;
    while(i == 0)
    {
        stack_a_is_sorted(stack_a, info);
        if(!info->sorted)
            sort_stack_a(stack_a, stack_b, info);
        else if (stack_b->f_element != NULL)
        {
            while (stack_b->f_element)   
            {  
                push_to_a(stack_a, stack_b, info);
                i = 1;
            }
        }
    }  
}


int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    t_sorted sort;
    t_info info;

    initialize_stacks(&stack_a, &stack_b, &info);
    create_stack(&argc, argv,&stack_a,&sort);   
    stack_a_is_sorted(&stack_a, &info);
    if(!info.sorted)
    {
        if(argc == 3)
            sort_2_nums(&stack_a);
        else if(argc == 4)
            sort_3_nums(&stack_a);
        else
            sort_the_rest(&stack_a, &stack_b, &info);  
    }
    re_arrange_stack(&stack_a, sort.sorted[0]); 
    printf("stack a\n");
    print_stack(stack_a.f_element);
    printf("stack b\n");
    print_stack(stack_b.f_element);
    return (0); 
}