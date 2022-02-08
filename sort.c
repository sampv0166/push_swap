#include "push_swap.h"

void sort_2_nums(t_stack *stack_a)
{
    if(stack_a->f_element->num > stack_a->f_element->next->num)
        swap(stack_a, "sa");
}

void sort_3_nums(t_stack *stack_a)
{
    if((stack_a->f_element->num > stack_a->f_element->next->num) && \
     (stack_a->f_element->num > stack_a->f_element->next->next->num))
    {
        rotate(stack_a, "ra");
    }
    else if((stack_a->f_element->next->num > stack_a->f_element->next->next->num) && \
            (stack_a->f_element->next->num >  stack_a->f_element->num))
    {
        reverse_rotate(stack_a, "rra");
    }
    if(stack_a->f_element->num > stack_a->f_element->next->num)
        swap(stack_a, "sa");
}


// void sort_to_array(t_sorted *sort, int *argc, char **argv, t_stack *stack_a, t_stack *stack_b)
// {
//     int i;
//     int j;
//     int atoi_check;

//     sort->sorted = (int *) malloc (sizeof(int) * (*argc + 1));
//     if(!sort->sorted)
//          error(sort, argv, stack_a, stack_b);
//     i = 1;
//     j = 0;
//     while(i < (*argc))
//     {
//         atoi_check = 0;
//         sort->sorted[j] = ft_atoi(argv[i], &atoi_check);
//         if(atoi_check == 1)
//              error(sort, argv, stack_a, stack_b);
//         i++;
//         j++;
//     }
//     argv[i] = NULL;
//     quickSort(sort->sorted, 0, *argc - 2);
//     sort->length = (*argc) - 1;
// }

void fix_stack(int *ra_count, int *rra_count,t_stack *stack_a)
{
    int i;

    i = 0;
    if(*ra_count <= *rra_count)
    {
        while(i < *ra_count)
        {
            rotate(stack_a,"ra");
            i++;
        }
    }
    else
    {
        while(i < *rra_count)
        {
            reverse_rotate(stack_a, "rra");
            i++;
        }
    }
}

void re_arrange_stack(t_stack *stack_a, int nextnumber)
{
    t_list *stack_ra;
    t_list *stack_rra;
    int ra_count;
    int rra_count;

    ra_count = 0;
    rra_count = 0;
    stack_ra = stack_a->f_element;
    stack_rra = stack_a->f_element;

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
    fix_stack(&ra_count,&rra_count,stack_a);
}

