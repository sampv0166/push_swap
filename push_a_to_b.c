#include "push_swap.h"

int get_size_of_unsorted_list(t_stack *stack, t_info *info)
{
    t_list *temp_list;
    int size;

    temp_list = stack->f_element;
    size = 0;
    while(temp_list)
    {
        temp_list = temp_list->next;
        size++;
    }
    return(size);   
}


int find_median(t_stack *stack,t_info *info, int size)
{
    t_list *temp_list;
    int s;
    int     numbers[size];
    int median;

    s = 0;
    temp_list = stack->f_element;
    while(s < size)
    {
        numbers[s] = temp_list->num;
        temp_list = temp_list->next;
        s++;
    }
    quickSort(numbers, 0, s);
     if(size % 2 == 0)
     {
         median = ((numbers[s / 2] + numbers[(s / 2) + 1]) / 2 );
     }
     else
     {
         median = numbers[s / 2];
   }
    return (median);
}


void divide_stack_a(t_stack *stack_a, t_stack *stack_b, t_info *info, int median, int size)
{
    int i;
    i = 0;
    while(i < size)
    {
        if(stack_a->f_element && stack_a->f_element->num <= median)   
            push(stack_a, stack_b, "pb");
        else
            rotate(stack_a, "ra");
        i++;    
    }
}

void sort_stack_a(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
    int size;
    int median;

    size = get_size_of_unsorted_list(stack_a, info);
    
    if(size > 3)
    {
          median = find_median(stack_a, info, size);
          divide_stack_a(stack_a, stack_b, info, median,size);
    }
    else
    {
        if(size == 3)
            sort_3_nums(stack_a);
        if(size == 2)
            sort_2_nums(stack_a);
    } 
}
