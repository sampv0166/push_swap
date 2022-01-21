#include "push_swap.h"

int get_size_of_unsorted_list(t_stack *stack, t_stack *stack_b)
{
    //? WHAT If THE STACK IS EMPTY ???? 
    t_list *temp_list;
    int size;

    temp_list = stack->f_element;
    size = 0;
    //TODO : ALSO CHECK IF WE REACHEDE POSITION WHICH IS ALREADY SORTED
    while(temp_list && temp_list->num != stack->partitions[0])
    {
        temp_list = temp_list->next;
        size++;
    }
    return(size);   
}

int divide_stack_a(t_stack *stack_a,t_stack *stack_b, int size, int *median)
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
        stack_count = get_size_of_unsorted_list(stack_a, stack_b);
        if(stack_count == 2 || stack_count == 3)
        {
           // stack_b->partitions[stack_b->min++] = stack_b->f_element->num;
            return (ra_count);  
        }
        if(stack_a->f_element->num <= *median)
        {
            push(stack_a, stack_b, "pb");
        }
        else
        {
            rotate(stack_a,  "ra");
            ra_count++;
        }
        s++;
    }
    stack_b->partitions[stack_b->min++] = stack_b->f_element->num;
    return (ra_count);
}

int find_median(t_list *list, int size)
{
    t_list *temp_list;
    int s;
    int     numbers[size];
    int median;

    s = 0;
    temp_list = list;
    while(s < size)
    {
        numbers[s] = temp_list->num;
        temp_list = temp_list->next;
        s++;
    }
    quickSort(numbers, 0, s);
    median = numbers[s / 2];

    return (median);
}

void rotate_back_stack_a(t_stack *stack_a, int ra_count)
{
    int count ; 

    count = ra_count;

    while(count && stack_a->partitions[0])
    {
        reverse_rotate(stack_a, "ra");
        count--;
    }
}

int partition_stack_a(t_stack *stack_a, t_stack *stack_b)
{
    int size;
    int median;
    int ra_count;

    if(stack_b->f_element && stack_a->partitions[1] == 1)
        return(0);
    size = get_size_of_unsorted_list(stack_a ,stack_b);
    printf("size ===== %d\n" ,size);
    if(size != 3 && size > 3)
    {
        median = find_median(stack_a->f_element, size);
        printf("median = %d\n", median);
        ra_count = divide_stack_a(stack_a,stack_b, size, &median);
        if(ra_count > 0)
            rotate_back_stack_a(stack_a, ra_count);
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
        printf("%d", stack_a->partitions[0]);
        printf("STACK B AFTER SORTING \n");
        print_stack(stack_b->f_element);
        printf("STACK A AFTER SORTING \n");
        print_stack(stack_a->f_element);
        return(0);
    }
    return (1);
   // 
    // else
    // {
    //     sort_3_nums(stack_a);
    //     set_stack_a_sort();  
    // }
}

