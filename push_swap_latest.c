#include "push_swap.h"

long	special_median_a(t_stack *a,  t_info *info, int size)
{
	t_list	*tmp;
	int		arr[12];
	int		i;
	int		j[2];

	tmp = a->f_element;
	i = 0;
	while (i < size)
	{
		arr[i++] = tmp->num;
		tmp = tmp->next;
	}
	j[0] = -1;
	while (j[0]++ < i)
	{
		j[1] = j[0];
		while (++j[1] < i)
			if (arr[j[0]] < arr[j[1]])
			{
				arr[11] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[11];
			}
	}
	return (arr[3]);
}
long	special_median_b(t_stack *a,  t_info *info, int size)
{
	t_list	*tmp;
	int		arr[7];
	int		i;
	int		j[2];

	tmp = a->f_element;
	i = 0;
	while (i < size)
	{
		arr[i++] = tmp->num;
		tmp = tmp->next;
	}
	j[0] = -1;
	while (j[0]++ < i)
	{
		j[1] = j[0];
		while (++j[1] < i)
			if (arr[j[0]] > arr[j[1]])
			{
				arr[6] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[6];
			}
	}
	return (arr[2]);
}

void initialize_stacks(t_stack *stack_a, t_stack *stack_b, int argc, t_info *info)
{
    //int arr[argc];
    // int i;

    // i = 0;
    // while(i < argc)
    // {
    //     arr[i] = NULL;
    //     i++;
    // }
   // t_list **ptr;

    stack_b->f_element = NULL;
    stack_a->f_element = 0;
    info->sorted = 0;    
    info->instr = 0;
    info->a_top = 2147483648;
    info->b_top = -1;
    stack_b->p = malloc(sizeof (t_list*) * argc);
   // stack_b->p = ptr;
    //stack_a->partitions = arr;;
    stack_b->p[0] = NULL;
   //stack_b->partitions = NULL;
    //stack_->partitions = NULL;
    info->flag = 0;
    stack_a->count = 0;
    stack_b->count = 0;
        stack_b->max = 0;
    stack_a->max = 0;
}

static void sort_to_array(t_sorted *sort, int argc, char **argv)
{
    int i;
    int j;

    sort->sorted = (int *) malloc (sizeof(int) * argc);
    i = 1;
    j = 0;
    while(i < argc)
    {
        sort->sorted[j] = ft_atoi(argv[i]);
        i++;
        j++;
    }
    argv[i] = NULL;
    quickSort(sort->sorted, 0, argc - 2);
    sort->length = argc - 1;
}

static void create_list(int argc, char **argv, t_stack *stack)
{
    int i;
    int j;

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

int get_size_of_unsorted_list(t_stack *stack, t_info *info)
{
    t_list *temp_list;
    int size;

    temp_list = stack->f_element;
    size = 0;
    while(temp_list && temp_list->num != info->a_top)
    {
        temp_list = temp_list->next;
        size++;
    }
    return(size);   
}

void stack_a_is_sorted(t_stack *stack_a, t_info *info)
{
   // int count;
    t_list *temp_list;
    int f;
    int j;

    j = 0;

    f = 0;
  //  count = get_size_of_unsorted_list(stack_a, info);
    temp_list = stack_a->f_element;
    while(temp_list)
    {
       
        if(temp_list->next && temp_list->num  > temp_list->next->num)
        {
            f = 1;
            break ;
        }
        temp_list = temp_list->next;  
        j++;
    }
    if(f == 1)
    {
         info->sorted = 0;
       
    }  
    else    
    {
  info->a_top = stack_a->f_element->num;
 info->sorted = 1;
    }
       

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
    // if(info->flag)
    // {
    //     if(size == 4)
    //         median = numbers[3];
    //     if(size == 5)
    //         median = numbers[4];    
    // }    
   // else
    // if(size % 2 == 0)
    // {
    //     median = ((numbers[s / 2] + numbers[(s / 2) + 1]) / 2 );
    // }
    // else
    // {
         median = numbers[s / 2];
   // }
   

    return (median);
}

int get_list_count(t_stack *stack)
{
    t_list *temp;
    int i;

    temp = stack->f_element;

    while(temp)
    {
        i++;
        temp =  temp->next;
    }
    return (i);
}

void divide_stack_a(t_stack *stack_a, t_stack *stack_b, t_info *info, int median, int size)
{
    int ra_count;
    int i;
    i = 0;
    t_list *new;
    int j;
    j = 0;

    ra_count = 0;
 
    while(i < size)
    {
        if(stack_a->f_element->num < median)
        {   
            // if(stack_b->f_element)
            // {
            //     //j = find_next_number_in_stack_a(stack_b, stack_a->f_element->num, info,stack_b);
            //     if(stack_a->f_element->num < j)
            //     {
            //         push(stack_a, stack_b, "pb");
            //         swap(stack_b, "sb");
            //     }
            //     else
            //     {
            //         push(stack_a, stack_b, "pb");
            //     }
            // }
            // else
                push(stack_a, stack_b, "pb");
        }
        else
        {
            rotate(stack_a, "ra");
            ra_count++;
        }
            ;
        i++;    
    }
    // while(ra_count)
    // {
    //     if(info->a_top == 2147483648)
    //         ;
    //     else
    //         reverse_rotate(stack_a, "rra");          
    //     ra_count--;
    // }
    stack_b->p[++(info->b_top)] = stack_b->f_element;
}

void sort_stack_a(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
    int size;
    int median;

    size = get_size_of_unsorted_list(stack_a, info);
    
    if(size > 3)
    {
    //     if(size > 3 && size <= 11)
    //     {
    //     median = special_median_a(stack_a, info, size);
    //       divide_stack_a(stack_a, stack_b, info, median,size);
    //     }
    //    else
    //    {
          median = find_median(stack_a, info, size);
          divide_stack_a(stack_a, stack_b, info, median,size);
      // }
    }
    else
    {
         
//         if(size == 50)
// {
//                 print_stack(stack_a->f_element);
//             print_stack(stack_b->f_element);
//           printf("\ntotal instructions : %d", stack_a->max + stack_b->max);    
//         exit(1);
// }
        if(size == 3)
        {
            sort_3_nums(stack_a);
            // t_list *temp;
            // int i;
            // temp = stack_a->f_element;
            // i = 0;
            // while (temp)
            // {
            //     temp = temp->next;
            //     i++;           
            // }
            // if(i > 10)
            // {
            //    printf("stack a\n");
           
            //  printf("stack b\n");
              print_stack(stack_a->f_element);
            //  printf("\ntotal instructions : %d", stack_a->max + stack_b->max);
            //     exit(1);
            // }
        }
            
        if(size == 2)
            sort_2_nums(stack_a);
        if(size == 1)
            info->a_top = stack_a->f_element->num;
        if(size == 0)
            info->a_top = stack_a->f_element->num;

    
    } 
}

int get_size_of_unsorted_list_b(t_stack *stack, t_info *info)
{
    t_list *temp_list;
    int size;
    temp_list = stack->f_element;
    info->b_top--;
    size = 0;
    while(temp_list && temp_list != stack->p[info->b_top])
    {
        temp_list = temp_list->next;
        size++;
       
    }
    return(size);   
}

void sort_3_nums_b(t_stack *stack_a)
{
    if(stack_a->f_element->num < stack_a->f_element->next->num)
    {
        swap(stack_a, "sb");
    }
    if(stack_a->f_element->next->num < stack_a->f_element->next->next->num)
    {
        rotate(stack_a, "rrb");
        swap(stack_a, "sb");
        reverse_rotate(stack_a, "rrb");
    }
    if(stack_a->f_element->num < stack_a->f_element->next->num)
    {
        swap(stack_a, "sb");
    }
}

void sort_2_nums_b(t_stack *stack_a)
{
    if(stack_a->f_element->num < stack_a->f_element->next->num)
    {
        swap(stack_a, "sa");
    }
}

void push_to_a(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
    t_list *temp_a;
    t_list *temp_b;
    t_list *l_temp_b;
    int j;

    temp_a = stack_a->f_element;
    temp_b = stack_b->f_element;
    l_temp_b = stack_b->f_element;

   
    j = 0;
    int number_to_push;
    number_to_push = 0;
    int instr;
    int in;

    while(temp_b)
    {
        j = find_next_number_in_stack_a(stack_a, stack_b->f_element->num,info,stack_b);
        temp_b = temp_b->next;
                printf("\nrrb = %d\n", info->b_rrb_count);
    printf("\nrb = %d\n", info->b_rb_count);
      printf("\nj = %d\n", j);
    }

    if(info->b_rb_count > info->b_rrb_count)
    {
        instr = 1;
    }
    else
    {
        instr = 0;
    }
    if(j < stack_a->f_element->num)
    {
        in = 1;
    }
    else
    {
        in = 0;
    }
    if(instr)
    {
        while (stack_b->f_element->num != j)
        {   
            // if(in == 0)
            // {
            //     rr(stack_a, stack_b);
            //     in = 1;
            // }
            rotate(stack_b, "rb");
        }    
    }
    else
    {
      while (stack_b->f_element->num != j)
        {
            reverse_rotate(stack_b, "rrb");
        }
    }


    //    if(j < stack_a->f_element->num)
    // {
    push(stack_b, stack_a, "pa");
    // }
    // else
    // {
    //     push(stack_b, stack_a, "pa");
    //     swap(stack_a, "sa");
    // }

    // exit(1);
}   

void push_b_to_a(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
    int size;
    int median;
    int rb_count;
    int p_count;
    int i;

    info->flag = 0;
    i = 0;
    rb_count = 0;
    p_count = 0;
    size = get_size_of_unsorted_list_b(stack_b, info);
    if(size > 3)
    {
        // if(size > 3 && size <=11)
        // {
        //     median = special_median_b(stack_b, info, size);
        // }
        // else
        // {
             median = find_median(stack_b, info, size);
        // }
        while(i < size)
        {
            if(stack_b->f_element->num > median)
            {

         
                push(stack_b, stack_a, "pa");

                p_count++;
            }
            else
            {
                rotate(stack_b,"rb");
                rb_count++;
            }
            i++;
        }
        while (rb_count && stack_b->p[info->b_top - 1])
        {
            reverse_rotate(stack_b, "rrb");
            rb_count--;
        }
        // if(p_count)
        //     info->b_top--;
        //ft_lstadd_front(&stack_b->p, stack_b->f_element);
        stack_b->p[++(info->b_top)] = stack_b->f_element;
    }
    // else if(size > 3)
    // {
    //     info->flag =  1;
    //     median = find_median(stack_b, info, size);
    //     while(i < size)
    //     {
    //         if(stack_b->f_element->num > median)
    //         {
    //             push(stack_b, stack_a, "pa");
    //             p_count++;
    //         }
    //         else
    //         {
    //             rotate(stack_b,"rb");
    //             rb_count++;
    //         }
    //         i++;
    //     }
    //     while (rb_count && stack_b->p[info->b_top - 1])
    //     {
    //         reverse_rotate(stack_b, "rrb");
    //         rb_count--;
    //     }
    //     // if(p_count)
    //     //     info->b_top--;
    //     //ft_lstadd_front(&stack_b->p, stack_b->f_element);
    //     stack_b->p[++(info->b_top)] = stack_b->f_element;
    // }
    else
    {
        // sort_2_nums_b(stack_b);
     
        // reverse_rotate(stack_b, "rrb");
        // reverse_rotate(stack_b, "rrb");
        // sort_2_nums_b(stack_b);
        // push(stack_b, stack_a, "pa");

        // if(p_count)
        //     info->b_top--;
        //ft_lstadd_front(&stack_b->p, stack_b->f_element);
      //  stack_b->p[++(info->b_top)] = stack_b->f_element;
 
        if(size == 3)
        {
            //exit(1);
            sort_3_nums_b(stack_b);
            push(stack_b,stack_a, "pa");
            push(stack_b,stack_a, "pa");
            push(stack_b,stack_a, "pa");
            info->a_top = stack_a->f_element->num;
            
            // t_list *temp;
            // int i;
            // i= 0;
            // temp = stack_a->f_element;
            // while (temp)
            // {
            //     temp = temp->next;
            //     i++;           
            // }
            // if(i > 10)
            // {
            //   printf("stack a\n");
            //  print_stack(stack_a->f_element);
            //  printf("stack b\n");
            //   print_stack(stack_b->f_element);
            //  printf("\ntotal instructions : %d", stack_a->max + stack_b->max);
            // exit(1);
            // }
             
        }    
        if(size == 2)
        {
            sort_2_nums_b(stack_b);
            push(stack_b,stack_a, "pa");
            push(stack_b,stack_a, "pa");
            info->a_top = stack_a->f_element->num;
        }
        if(size == 1)
            printf("here 1 b");   
        if(size == 0)
            printf("here 0 b");   
    }
}

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    t_info info;
    t_sorted sort;
     int i;
//     int  k;
   // int j;

    // i = 0;
//     k = 0;
//     j = 0;
    initialize_stacks(&stack_a, &stack_b, argc, &info);
    sort_to_array(&sort, argc, argv); 
    create_list(argc, argv, &stack_a);
// //    // find_next_number_in_stack_a(&stack_a, sort.sorted[sort.length / 2]);
//     while(i < (sort.length - 1) / 2)
//     {
//         push(&stack_a, &stack_b, "pb");
//         i++;
//     }   
 
//     i = 0;
//     k = 0;
    // while(i < 50)
    // {
    //      if(stack_b.f_element->num > sort.sorted[25])
    //      {
             

    //             push(&stack_b, &stack_a, "pa");
    //         k++;
    //      }
                   
    //     else
    //      {

    //         rotate(&stack_b, "rb");
            
    //      }
    //     i++;
    // }

    //         i = 0;

    // while(i < 25)
    // {
    //             j = find_next_number_in_stack_a(&stack_b, stack_a.f_element->num);
    //             if(stack_a.f_element->num < j)
    //             {
    //                 push(&stack_a, &stack_b, "pa");
    //                swap(&stack_b, "sb");
    //             }
    //             else
    //             {
    //                 push(&stack_a, &stack_b, "pa");
                      
    //             }
    //         k++;

    //     i++;
    // }
    // int min ; 
    //   min = sort.sorted[0];
    // find_number_of_moves(&stack_b, min);
    //    print_stack(stack_a.f_element);
    // print_stack(stack_b.f_element)  ;
    // printf("\n%d", stack_a.max + stack_b.max);
   // exit(1);
    info.a_ra_count = 0;
    info.b_rb_count = 0;
    info.a_rra_count = 0;
    info.b_rrb_count = 0;
    //TODO : verify input and check if its already sorted
    while(1)
    {
        if(stack_a.f_element)
            stack_a_is_sorted(&stack_a, &info);
        if(info.sorted && stack_b.f_element == NULL)
            break ;  
        if(!info.sorted)
        {
            sort_stack_a(&stack_a, &stack_b, &info);
        }
        else if (stack_b.f_element != NULL)
        {
             printf("\n---------------------\n");
         while (stack_b.f_element)
            
         {  
                  print_stack(stack_a.f_element);
                 print_stack(stack_b.f_element);
                       printf("\ntotal instructions : %d", stack_a.max + stack_b.max);
                 exit(1);
                 
              push_to_a(&stack_a, &stack_b, &info);
         }

        printf("stack a\n");
        print_stack(stack_a.f_element);
        printf("stack b\n");
        print_stack(stack_b.f_element);
        printf("\ntotal instructions : %d", stack_a.max + stack_b.max);
        exit(1);
        }
    }
        printf("stack a\n");
        print_stack(stack_a.f_element);
        printf("stack b\n");
        print_stack(stack_b.f_element);
        printf("\ntotal instructions : %d", stack_a.max + stack_b.max);
}