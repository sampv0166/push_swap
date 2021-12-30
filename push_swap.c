#include "push_swap.h"

// static void initialize_stacks()
// {

// }


static void convert_char_to_integer(int argc, char **argv, t_stack *stack)
{
    int i;
    int j;

    t_list *temp_list;
    t_list *stack_a;
    t_sorted sort;

    sort.sorted = (int *) malloc (sizeof(int) * argc);
    stack_a = ft_lstnew(ft_atoi(argv[1]));
    //sort.sorted[0] = ft_atoi(argv[1]);
    i = 2;
    while(i < argc)
    {
        temp_list = ft_lstnew(ft_atoi(argv[i]));
        ft_lstadd_back(stack_a, temp_list);
        i++;
    }
    i = 1;
    j = 0;
    while(i < argc)
    {
        sort.sorted[j] = ft_atoi(argv[i]);
        i++;
        j++;
       // printf("%d\n", sort.sorted[0]);
    }
    argv[i] = NULL;
    i = 0;
    //     while(i < argc - 1)
    // {
    //     printf("%d\n", sort.sorted[i]);
    //     i++;
    // } 
    stack->count = argc - 1;
    stack->f_element = stack_a;
    quickSort(sort.sorted, 0, argc - 2);
    while(i < argc - 1)
    {
        printf("%d\n", sort.sorted[i]);
        i++;
    }
    sort.middle = sort.sorted[(argc - 1) / 2];
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
     //print_stack(stack_a.f_element); 
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
    // rotate(&stack_a);
    // print_stack(stack_a.f_element);  
    // rotate(&stack_a);
    // print_stack(stack_a.f_element);
    t_list *temp_elem;
    temp_elem = stack_a.f_element;
    int num;

    num = 0;
    while(stack_a.f_element->next != NULL)
    {
        stack_a.f_element = stack_a.f_element->next;
    }
    return (0);
}