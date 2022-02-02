#include "push_swap.h"

void stack_a_is_sorted(t_stack *stack_a, t_info *info)
{
    t_list *temp_list;
    int f;
    int j;

    j = 0;
    f = 0;
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
        info->sorted = 0;   
    else    
        info->sorted = 1;
}

void initialize_stacks(t_stack *stack_a, t_stack *stack_b, int argc, t_info *info)
{
    stack_b->f_element = NULL;
    stack_a->f_element = 0;
    info->sorted = 0;    
    info->instr = __INT_MAX__;
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
    while(i < argc - 1)
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

int chec_last_num(t_list *list)
{
    t_list *temp;

    temp   = list;

    while(temp)
    {
        if(temp->next->next == NULL)
            break ; 
        temp = temp->next;    
    }
    return (temp->next->num);
}

void divide_stack_a(t_stack *stack_a, t_stack *stack_b, t_info *info, int median, int size)
{
    int i;
    i = 0;
    while(i < size)
    {
        //find_number_of_moves(stack_a,)
        if(stack_a->f_element->num <= median)
        {   
            push(stack_a, stack_b, "pb");
        }
        else if(chec_last_num(stack_a->f_element) <= median)
        {
            reverse_rotate(stack_a, "rra");
        }
        else
        {
            rotate(stack_a, "ra");
        }
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
        {
            sort_3_nums(stack_a);
        }
        if(size == 2)
            sort_2_nums(stack_a);
    } 
}


void init_temp_info(t_info *temp_info)
{
    temp_info->instr = 0;
    temp_info->a_rra_count = 0;
    temp_info->a_ra_count = 0;

    temp_info->b_rrb_count = 0;
    temp_info->b_rb_count = 0;
    temp_info->number_to_push = 0;
}

void store_instructions(t_info *info, t_info *temp_info,t_list *temp_b)
{
   info->instr  =     temp_info->instr ;
    info->a_rra_count  =  temp_info->a_rra_count ;
    info->a_ra_count  =  temp_info->a_ra_count ;

     info->b_rrb_count  = temp_info->b_rrb_count ;
     info->b_rb_count  = temp_info->b_rb_count ;
    info->number_to_push  = temp_b->num ;
}

void push_to_a(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
    t_info temp_info;
    t_list *temp_b;
    int num ; 

    num = 0;
    temp_b = stack_b->f_element;
    info->instr = 2147483648;
    info->a_rra_count = 0;
    info->a_ra_count = 0;

    info->b_rrb_count = 0;
    info->b_rb_count = 0;
    info->number_to_push = 0;
    while(temp_b)
    {
        init_temp_info(&temp_info);
        temp_info.number_to_push = find_next_number_in_stack_a(stack_a,temp_b->num,info,stack_a);

        find_number_of_moves_stack_a(stack_a, temp_info.number_to_push ,stack_b, &temp_info);
        find_number_of_moves_stack_b(stack_b, &temp_info, temp_b);
        temp_info.instr = temp_info.a_ra_count + temp_info.a_rra_count + temp_info.b_rb_count + temp_info.b_rrb_count;
        if(info->instr > temp_info.instr)
        {
            store_instructions(info, &temp_info,temp_b);
            num = temp_info.number_to_push;
        }
            
        temp_b = temp_b->next;
    }
    if(info->number_to_push > num)
            info->a_ra_count = info->a_ra_count  + 1;
    if(info->a_ra_count)
    {
        while(info->a_ra_count)
        {
            rotate(stack_a, "ra");
            info->a_ra_count = info->a_ra_count - 1;
        }
    }
    if(info->a_rra_count)
    {
           while(info->a_rra_count)
        {
            reverse_rotate(stack_a, "rra");
            info->a_rra_count = info->a_rra_count - 1;
        }
    }
    if(info->b_rb_count)
    {
        while(info->b_rb_count)
        {
            rotate(stack_b, "rb");
            info->b_rb_count = info->b_rb_count - 1;
        }
    }
    else if( info->b_rrb_count)
    {
        while(info->b_rrb_count)
        {
            reverse_rotate(stack_b, "rrb");
            info->b_rrb_count = info->b_rrb_count - 1;
        }
    }
    push(stack_b,stack_a, "pa");
}

void sort_the_rest(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
    int i;

    i = 0;
    while(i == 0)
    {
        stack_a_is_sorted(stack_a, info);
        if(!info->sorted)
            sort_stack_a(stack_a, stack_b, info);
        else if (stack_b->f_element != NULL)
        {
            while (stack_b->f_element)   
            {  
                push_to_a(stack_a, stack_b, info);
                i = 1;
            }
        }
    }  
}

static void create_list2(int *argc, char **argv, t_stack *stack)
{
    int i;
    int j;
    t_list *temp_list;
    t_list *stack_a;

    i = 0;
    while(argv[i])
        i++;
    *argc = i + 1;    
    stack_a = ft_lstnew(ft_atoi(argv[0]));

    i = 1;
    while(i < *argc - 1) 
    {
        temp_list = ft_lstnew(ft_atoi(argv[i]));
        ft_lstadd_back(stack_a, temp_list);
        i++;
    }
    stack->count = *argc - 1;
    stack->f_element = stack_a;
}

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    t_info info;
    t_sorted sort;
    int i;
 
    initialize_stacks(&stack_a, &stack_b, argc, &info);
    
    if(argc == 2)
    { 
        create_list2(&argc, ft_split(argv[1],' '), &stack_a);
        sort_to_array(&sort, argc, ft_split(argv[1],' '));
    }
    else
    {
        create_list(argc, argv, &stack_a);
        sort_to_array(&sort, argc, argv); 
    }

    print_stack(stack_a.f_element);
    stack_a_is_sorted(&stack_a, &info);
    if(info.sorted)
    {
        exit(1);
    }
      
    if(argc == 3)
        sort_2_nums(&stack_a);
    else if(argc == 4)
        sort_3_nums(&stack_a);
    // else if(argc == 6)
    // {
    //     sort_5_nums(&stack_a, &stack_b, &sort, &info);
    // }
    else
        sort_the_rest(&stack_a, &stack_b,&info) ;       

    printf("stack a\n");
    print_stack(stack_a.f_element);
    printf("stack b\n");
    print_stack(stack_b.f_element);
    printf("\ntotal instructions : %d", stack_a.max + stack_b.max);
}