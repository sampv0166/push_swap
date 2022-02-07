#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    t_sorted sort;
    t_info info;

    initialize_stacks(&stack_a, &stack_b, &info);
	







    create_stack(&argc, argv,&stack_a,&sort); 
    stack_a_is_sorted(&stack_a, &info);
    printf("\nargc -- %d\n", argc);
    if(!info.sorted)
    {
        if(argc == 2)
            sort_2_nums(&stack_a);
        else if(argc == 3)
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