#include "push_swap.h"

void sort_2_nums(t_stack *stack_a)
{
    if(stack_a->f_element->num > stack_a->f_element->next->num)
    {
        swap(stack_a, "sa");
    }
}

void sort_3_nums(t_stack *stack_a)
{
    if((stack_a->f_element->next->next->num > stack_a->f_element->next->num) && (stack_a->f_element->next->next->num > stack_a->f_element->num))
    {
        swap(stack_a, "sa");
        return ;
    }
    if(stack_a->f_element->num > stack_a->f_element->next->num)
    {
        swap(stack_a, "sa");
    }
    if(stack_a->f_element->next->num > stack_a->f_element->next->next->num)
    {
        rotate(stack_a, "rra");
        swap(stack_a, "sa");
        reverse_rotate(stack_a, "rra");
    }
}
void find_number_of_moves_stack_a(t_stack *stack_a, int nextnumber, t_stack *stack_b, t_info *temp_info)
{
    t_list *stack_ra;
    int ra_count;
    int rra_count;

    ra_count = 0;
    rra_count = 0;
    stack_ra = stack_a->f_element;
    while(stack_ra && stack_ra->num != nextnumber)
    {
       
        stack_ra = stack_ra->next;
        ra_count++;
    }
    while(stack_ra != NULL)
    {
        stack_ra = stack_ra->next;
        rra_count++;
    }
    if(ra_count <= rra_count)
        temp_info->a_ra_count = ra_count;
    else
    {
         temp_info->a_rra_count = rra_count;  
    }
         
}

void find_number_of_moves_stack_b(t_stack *stack_b, t_info *temp_info, t_list *temp_b)
{
    t_list *stack_rb;
    int rb_count;
    int rrb_count;

    rb_count = 0;
    rrb_count = 0;
    stack_rb = stack_b->f_element;
    while(stack_rb && stack_rb->num != temp_b->num)
    {
        stack_rb = stack_rb->next;
        rb_count++;
    }
    while( stack_rb != NULL)
    {
        stack_rb = stack_rb->next;
        rrb_count++;
    }
    if(rb_count <= rrb_count)
        temp_info->b_rb_count = rb_count;
    else
        temp_info->b_rrb_count = rrb_count;    
}

void find_number_of_moves(t_stack *stack_a, int nextnumber, t_stack *stack_b, t_info *info)
{
    t_list *stack_ra;
    t_list *stack_rra;
    int ra_count;
    int rra_count;

    ra_count = 0;
    rra_count = 0;
    int i;

    i = 0;
    stack_ra = stack_a->f_element;
    stack_rra = stack_a->f_element;

    while(stack_ra->num != nextnumber)
    {
        stack_ra = stack_ra->next;
        ra_count++;
    }
    while(stack_ra != NULL)
    {
        stack_ra = stack_ra->next;
        rra_count++;
    }
    if(ra_count <= rra_count)
    {
        while(i < ra_count)
        {
           rotate(stack_a,"ra");
            i++;
        }
    }
    else
    {
        while(i < rra_count)
        {
           reverse_rotate(stack_a, "rra");
            i++;
        }
    }
}

int find_next_number_in_stack_a(t_stack *stack_a, int number, t_info *info,t_stack *stack_b)
{
    t_list *list;

    list = stack_a->f_element;
    int min;
    int t;
    int next_number;
    int n;
    int i;
    int j;

    i = 0;
    j = 0;

    min =  number - list->num ;
    if (min < 0)
        min = min * -1;
    next_number = list->num;
    while(list != NULL)
    {
        n = list->num;
        t = n - number;
        if (t < 0)
                t = t * -1;
        if((t) < min)
        {
            min = number - n;
            if (min < 0)
                min = min * -1;
            next_number = list->num;
            j = i;
        }
        list = list->next;
        i++;
    }
    return(next_number);
}

void sort_5_nums(t_stack *stack_a, t_stack *stack_b, t_sorted *sort)
{
    t_list *stack_a_temp;

    while(stack_a)
    {
        
    }

    sort_3_nums(stack_a);

    int i;
    i = 2;
    while(i)
    {
        if(stack_b->f_element->num < stack_a->f_element->num)
        {
            push(stack_b, stack_a, "pa");
        }
        else if(stack_b->f_element->num > sort->sorted[4])
        {
            push(stack_b, stack_a, "pa");
            rotate(stack_a, "ra");
        }
        else if(stack_b->f_element->num < sort->sorted[2])
        {
            push(stack_b, stack_a, "pa");
            swap(stack_a, "sa");
        }
        i--;
    }
}

/*
TODO : STEPS FOR SORTING ALGORITHAM
*FIND THE NUMBER THAT IS NEAR TO STACK_B_TOP IN STACK_A
*ROTATE STACK_A UNTILL WE REACH THE NEAREST NUMBER THAT WE FOUND
*IF THE NUMBE BEING PUSHED IS LESS THAT NEAREST NUMBER ---PUSH
*IF THE NUMBER BEING PUSHED IS GREATER PUSH AND SWAP
*/