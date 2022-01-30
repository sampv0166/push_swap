#include "push_swap.h"





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

int divide_stack_b(t_stack *stack_b,t_stack *stack_a, int size, int *median)
{
    int s;
    int ra_count;
    int sz;
    int stack_count;

    sz = size;
    ra_count = 0;
    s = 0;
    while(s < sz)
    {   
        if(stack_a->f_element->num > *median)
        {
            push(stack_b, stack_a, "pa");
        }
        else
        {
            rotate(stack_b,  "rb");
            ra_count++;
            if(ra_count == 1)
                    stack_b->partitions[stack_b->min++] = stack_b->f_element->num;
        }
        s++;
    }

    return (ra_count);
}



int push_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
    int size;
    int median;
    int rb_count;

    size = get_size_of_unsorted_list_b(stack_b, stack_a);
    printf("count ========== %d\n", size);

    if(size != 3 && size > 3)
    {
        median = find_median(stack_b->f_element, size);
        printf("median = %d\n", median);
        rb_count = divide_stack_b(stack_b,stack_a, size, &median);
        if(rb_count > 0)
            rotate_back_stack_a(stack_b, rb_count);
        printf("\nkkkkkkkkkkkkkkkkk=== %d\n", stack_b->partitions[0]);    
        printf("\nkkkkkkkkkkkkkkkkk=== %d\n", stack_b->partitions[1]);  
        printf("\nkkkkkkkkkkkkkkkkk=== %d\n", stack_b->partitions[2]);
        return(1);
    }
    else
    {
        if(size == 2)
            sort_2_nums(stack_a);
        if(size == 3)
             sort_3_nums(stack_a);
        stack_a->partitions[0] = stack_a->f_element->num;
        stack_a->partitions[1] == 0;
        // printf("%d", stack_a->partitions[0]);
        // printf("STACK B AFTER SORTING \n");
        // print_stack(stack_b->f_element);
        // printf("STACK A AFTER SORTING \n");
        // print_stack(stack_a->f_element);
        return(0);
    }





    // print_stack(stack_a->f_element);
    // print_stack(stack_b->f_element);
    printf("ops = %d\n", stack_a->max + stack_b->max);
    // while(stack_b->f_element->num != stack_b->partitions[stack_b->min - 1])
    // {
    //     if(size == 2)
    //     {
             
    //         if(stack_b->f_element->num < stack_b->f_element->next->num)
    //         {
    //             swap(stack_b,"sb");
    //             push(stack_b, stack_a, "pa");
    //             push(stack_b, stack_a, "pa");
    //             stack_b->min--;
    //             stack_a->partitions[0] = stack_a->f_element->num;
    //             stack_a->partitions[1] = 1;
    //             break ;
    //         }
    //         else
    //         {
    //             push(stack_b, stack_a, "pa");
    //             push(stack_b, stack_a, "pa");
    //             stack_b->min--;
    //             stack_a->partitions[0] = stack_a->f_element->num;
    //             stack_a->partitions[1] = 1;
    //             break ;
    //         }
    //     }
    //     else
    //     {
    //         push(stack_b, stack_a, "pa");
    //         stack_a->partitions[1] = 0;
    //     }
    // }
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
                if(push_b_to_a(&stack_a, &stack_b))
                {
                    continue ;
                }
                else
                {
                    partition_stack_a(&stack_a, &stack_b);
                }
            }
            //TODO :CHANGE THE PARTITION VALUE OF STACK A BECAUSE ALL ELEMENTS 
            //*IN STACK A ARE SORTED
            //partition_stack_b(stack_b, stack_a);
    }
}
