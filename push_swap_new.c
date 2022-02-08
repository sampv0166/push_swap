# include "push_swap.h"

static char	*ft_strjoin(char *saved_line, char *buffer)
{
	char	*new_string;
	int		total_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	total_len = ft_strlen(saved_line) + ft_strlen(buffer) + 2;
	new_string = (char *) malloc(sizeof(char) * (total_len));
	if (new_string == NULL)
		exit(0);
	while (saved_line[i])
		new_string[i++] = saved_line[j++];
	j = 0;
	while (buffer[j])
		new_string[i++] = buffer[j++];
	new_string[i++] = ' ';			
	new_string[i] = '\0';
	if(saved_line)
		free(saved_line);
	return (new_string);
}

char *join_args(char **argv)
{
	int i;
	char *join;

	join = malloc (sizeof (char) * 1);
	i = 1;
	while(argv[i])
	{
		join = ft_strjoin(join, argv[i]);
		i++;
	}
	return (join);
}

char **split_and_join(int argc, char **argv)
{
	char *joined_args;
	char **split_args;
	int i;

	i = 0;
	joined_args = join_args(argv);
	split_args = ft_split(joined_args ,' ');
	return(split_args);
}

void sort_to_array(t_info *info, int argc)
{
    int i;
    int j;
    int atoi_check;


    info->sorted_arr = (int *) malloc(sizeof(int) * (argc));
	info->not_sorted_arr = (int *) malloc(sizeof(int) * (argc));
    if(!info->sorted_arr)
         exit(0);
    i = 0;
    j = 0;
    while(i < argc)
    {
        atoi_check = 0;
        info->sorted_arr[j] = ft_atoi(info->argmnts[i], &atoi_check);
		info->not_sorted_arr[j] = ft_atoi(info->argmnts[i], &atoi_check);
        if(atoi_check == 1)
             exit(0);
        i++;
        j++;
    }
    quickSort(info->sorted_arr, 0, argc - 1);
	print_array(info->sorted_arr, argc + 1);
}

int check_for_doubles(t_info *info, int argc)
{ 
	int ret;
	int i;
	int j;

	ret = 1;
	i  = 0;
	j = 0;
	while(i < argc - 1)
	{
		j = i + 1;
		if(info->sorted_arr[i] == info->sorted_arr[j])
		{
			ret = 0;
			return (ret);
		}
		while(j < argc)
		{
			if(info->sorted_arr[i] == info->sorted_arr[j])
			{
				ret = 0;
				return (ret);
			}
			j++;
		}
		i++;
	}
	return(ret);
}


int verify_input(int argc, t_info *info)
{
	int ret;

	ret = 1;
	if (!check_for_doubles(info, argc))
		ret = 0;
	return (ret);
}

int count_args_after_joining(char **arg)
{
	int i;

	i = 0;
	while(arg[i])
		i++;
	return (i);
}

static void create_list(t_info *info, t_stack *stack, t_stack *stack_b)
{
    int i;
    int j;
  
    t_list *temp_list;
    t_list *stack_a;
    stack_a = ft_lstnew(info->not_sorted_arr[0]);
    i = 1;
    while(i < info->length)
    {
        temp_list = ft_lstnew(info->not_sorted_arr[i]);
        ft_lstadd_back(stack_a, temp_list);
            stack->f_element = stack_a;
        i++;
    }
    stack->count = info->length - 1;
    stack->f_element = stack_a;
	print_stack(stack->f_element);
	//print_array(info->not_sorted_arr, )
}

void push_to_a(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
    int num; 

    num = 0;
    find_minimum_instruction(stack_a, stack_b, info, &num);
    if(info->number_to_push > num)
            info->a_ra_count = info->a_ra_count + 1;
    execute_rotation_instructions(info, num, stack_a, stack_b);
    execute_rev_rotation_instructions(info, num, stack_a, stack_b);
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

void initialize_stacks(t_stack *stack_a, t_stack *stack_b,t_info *info)
{
    stack_b->f_element = NULL;
    stack_a->f_element = NULL;
    info->sorted = 0;    
    info->instr = __INT_MAX__;
    stack_a->count = 0;
    stack_b->count = 0;
}


int main(int argc, char **argv)
{
	t_stack stack_a;
    t_stack stack_b;
    t_info info;
	int count;


	if(argc > 1)
		info.argmnts = split_and_join(argc, argv);
	count = count_args_after_joining(info.argmnts);
	info.length = count;	
	sort_to_array(&info, count);
	//print_array(&info.sorted, count);
	initialize_stacks
  	if(!verify_input(count, &info))
             exit(0);
	 create_list(&info,&stack_a, &stack_b);
	// printf("coutn == %d\n", info.sorted_arr[0]);
	// if(count == 2)
	// 	sort_2_nums(&stack_a);
	// else if(count == 3)
	// 	sort_3_nums(&stack_a);
	// else
	// 	sort_the_rest(&stack_a, &stack_b, &info);


	print_array(info.sorted_arr, count + 1);	
	re_arrange_stack(&stack_a, info.sorted_arr[0]); 
    printf("stack a\n");
    print_stack(stack_a.f_element);
    printf("stack b\n");
    print_stack(stack_b.f_element);
}