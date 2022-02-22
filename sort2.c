#include "push_swap.h"

void push_to_b_4nums(t_stack *stack_a,t_stack *stack_b,t_info *info)
{
    int max;
    int max2;

    max = info->sorted_arr[0];
    max2 = info->sorted_arr[1];

    if(stack_a->f_element->num == max || stack_a->f_element->num == max2)
        push(stack_a, stack_b, "pb");
    else if (stack_a->f_element->next->num == max || stack_a->f_element->next->num == max2)
    {
        rotate(stack_a, "ra");
        push(stack_a, stack_b, "pb");
    }
    else if (stack_a->f_element->next->next->num == max || \
            stack_a->f_element->next->next->num == max2)
    {
        reverse_rotate(stack_a, "rra");
        reverse_rotate(stack_a, "rra");
        push (stack_a, stack_b, "pb");
    }
    else if (stack_a->f_element->next->next->next->num == max || \
            stack_a->f_element->next->next->next->num == max2)
    {
        reverse_rotate(stack_a, "rra");
        push (stack_a, stack_b, "pb");
    }
}

void sort_4_nums(t_stack *stack_a,t_stack *stack_b,t_info *info)
{
    int max;
    
    max = info->sorted_arr[0];

    if(stack_a->f_element->num == max)
        push(stack_a, stack_b, "pb");
    else if (stack_a->f_element->next->num == max)
    {
        rotate(stack_a, "ra");
        push(stack_a, stack_b, "pb");
    }
    else if (stack_a->f_element->next->next->num == max)
    {
        reverse_rotate(stack_a, "rra");
        reverse_rotate(stack_a, "rra");
        push (stack_a, stack_b, "pb");
    }
    else if (stack_a->f_element->next->next->next->num == max)
    {
        reverse_rotate(stack_a, "rra");
        push (stack_a, stack_b, "pb");
    }
    sort_3_nums(stack_a);
    push(stack_b, stack_a, "pa");
}

void sort_5_nums(t_stack *stack_a,t_stack *stack_b,t_info *info)
{
   
    int max;
    int max2;
    t_list	*temp_list;
	int		s;
	int		median;
	int		*numbers;

	numbers = malloc (sizeof (int) * 5);
	if (!numbers)
		error(info, stack_a, stack_b);
	s = 0;
	temp_list = stack_a->f_element;
	while (s < 5)
	{
		numbers[s] = temp_list->num;
		temp_list = temp_list->next;
		s++;
	}
	quicksort(numbers, 0, 4);

    max =numbers[0];
    max2 = numbers[1];
    free (numbers);
   // print_array(info->sorted_arr, info->length + 1);

    if(stack_a->f_element->num == max || stack_a->f_element->num == max2)
        push(stack_a, stack_b, "pb");
    else if (stack_a->f_element->next->num == max || stack_a->f_element->next->num == max2)
    {
        rotate(stack_a, "ra");
        push(stack_a, stack_b, "pb");
    }
    else if (stack_a->f_element->next->next->next->next->num == max || stack_a->f_element->next->next->next->next->num == max2)
    {
        reverse_rotate(stack_a, "rra");
        push (stack_a, stack_b, "pb");
    }
    else if (stack_a->f_element->next->next->next->num == max || \
            stack_a->f_element->next->next->next->num == max2)
    {
        reverse_rotate(stack_a, "rra");
        reverse_rotate(stack_a, "rra");
        push (stack_a, stack_b, "pb");
    }
    else if (stack_a->f_element->next->next->num == max || \
            stack_a->f_element->next->next->num == max2)
    {
        rotate(stack_a, "ra");
        rotate(stack_a, "ra");
        push (stack_a, stack_b, "pb");
    }

    if(stack_a->f_element->num == max || stack_a->f_element->num == max2)
        push(stack_a, stack_b, "pb");
    else if (stack_a->f_element->next->num == max || stack_a->f_element->next->num == max2)
    {
        rotate(stack_a, "ra");
        push(stack_a, stack_b, "pb");
    }
    else if (stack_a->f_element->next->next->num == max || \
            stack_a->f_element->next->next->num == max2)
    {
        reverse_rotate(stack_a, "rra");
        reverse_rotate(stack_a, "rra");
        push (stack_a, stack_b, "pb");
    }
    else if (stack_a->f_element->next->next->next->num == max || \
            stack_a->f_element->next->next->next->num == max2)
    {
        reverse_rotate(stack_a, "rra");
        push (stack_a, stack_b, "pb");
    }


    sort_3_nums(stack_a);
   	if (stack_b->f_element->num < stack_b->f_element->next->num)
	{
		swap(stack_b, "sb");
	}
    push(stack_b, stack_a, "pa");
    push(stack_b, stack_a, "pa");
    //print_stack(stack_a->f_element);
}

void sort_6_nums(t_stack *stack_a,t_stack *stack_b,t_info *info)
{
   
    int max;
    int max2;

    max = info->sorted_arr[0];

    t_list	*temp_list;
	int		s;
	int		median;
	int		*numbers;

	numbers = malloc (sizeof (int) * 6);
	if (!numbers)
		error(info, stack_a, stack_b);
	s = 0;
	temp_list = stack_a->f_element;
	while (s < 6)
	{
		numbers[s] = temp_list->num;
		temp_list = temp_list->next;
		s++;
	}
	quicksort(numbers, 0, 5);

    max =numbers[0];
    free (numbers);

    if(stack_a->f_element->num == max)
        push(stack_a, stack_b, "pb");
    else if (stack_a->f_element->next->num == max)
    {
        rotate(stack_a, "ra");
        push(stack_a, stack_b, "pb");
    }
    else if (stack_a->f_element->next->next->next->next->num == max)
    {
        reverse_rotate(stack_a, "rra");
        reverse_rotate(stack_a, "rra");
        push (stack_a, stack_b, "pb");
    }
    else if (stack_a->f_element->next->next->next->next->next->num == max )
    {
        reverse_rotate(stack_a, "rra");
        push (stack_a, stack_b, "pb");
    }
    else if (stack_a->f_element->next->next->next->num == max)
    {
        reverse_rotate(stack_a, "rra");
        reverse_rotate(stack_a, "rra");
        reverse_rotate(stack_a, "rra");
        push (stack_a, stack_b, "pb");
    }
    else if (stack_a->f_element->next->next->num == max)
    {
        rotate(stack_a, "ra");
        rotate(stack_a, "ra");
        rotate(stack_a, "ra");
        push (stack_a, stack_b, "pb");
    }

    sort_5_nums(stack_a, stack_b, info);
    push(stack_b, stack_a, "pa");
   // print_stack(stack_a->f_element);
}