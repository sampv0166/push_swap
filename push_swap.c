#include "push_swap.h"

// static void initialize_stacks()
// {

// }
static void convert_char_to_integer(int argc, char **argv, t_stack *stack)
{
    int i;
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

    convert_char_to_integer(argc, argv, &stack_a);
    //delete this later
   // print_stack(stack_a.f_element);    
    // printf("stack count = %d\n", stack->count);
    //swap(&stack_a);
    //print_stack(stack_a.f_element);    
    // // delete before this
    stack_b.f_element = NULL;
   // push(&stack_a, &stack_b);
     print_stack(stack_a.f_element); 
//    print_stack(stack_b.f_element);     

//      push(&stack_a, &stack_b);
// //    // print_stack(stack_b.f_element);   
// //         //    
// // //    // return (0);
//   print_stack(stack_a.f_element); 
//     print_stack(stack_b.f_element);      

//     push(&stack_a, &stack_b);   

//     print_stack(stack_a.f_element); 
//     print_stack(stack_b.f_element);   

//     push(&stack_b, &stack_a);   

//     print_stack(stack_a.f_element); 
//     print_stack(stack_b.f_element); 
    rotate(&stack_a);
    print_stack(stack_a.f_element);  
    rotate(&stack_a);
    print_stack(stack_a.f_element); 
    return (0);
}