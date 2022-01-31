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
    // if(stack_a->f_element->num > stack_a->f_element->next->num)
    // {
    //     swap(stack_a, "sa");
    // }
}
void find_number_of_moves_stack_a(t_stack *stack_a, int nextnumber, t_stack *stack_b, t_info *temp_info)
{
    t_list *stack_ra;
    int ra_count;
    int rra_count;

    ra_count = 0;
    rra_count = 0;
    stack_ra = stack_a->f_element;
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
        temp_info->a_ra_count = ra_count;
    else
        temp_info->a_rra_count = rra_count;    
}

void find_number_of_moves_stack_b(t_stack *stack_b, t_info *temp_info, t_list *temp_b)
{
    t_list *stack_rb;
    int rb_count;
    int rrb_count;

    rb_count = 0;
    rrb_count = 0;
    stack_rb = stack_b->f_element;
    while(stack_rb->num != temp_b->num)
    {
        stack_rb = stack_rb->next;
        rb_count++;
    }
    while(stack_rb != NULL)
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
            ///push(stack_b,stack_a, "pa");
           rotate(stack_a,"ra");
            i++;
            //stack_a->f_element = stack_a->f_element->next;
        }
        // if(info->b_rb_count == 0)
        // {
        //     info->b_rb_count = ra_count;
        //     info->number_to_push = nextnumber;
            
        // }
        // else if(ra_count < info->b_rb_count)
        // {
        //     info->b_rb_count = ra_count;
        //     info->number_to_push = nextnumber;
        // }
    }
    else
    {
        while(i < rra_count)
        {
           reverse_rotate(stack_a, "rra");
            i++;
            //stack_a->f_element = stack_a->f_element->next;
        }
        // if(info->b_rrb_count == 0)
        // {
        //     info->b_rrb_count = rra_count;
        //      info->number_to_push = nextnumber;
        // }
        // else if(  rra_count < info->b_rrb_count)
        // {
        //     info->b_rrb_count = rra_count;
        //      info->number_to_push = nextnumber;
        // }
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
    while(list !=  NULL)
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

int find_next_number(t_stack *stack_a, int number, int p)
{
    t_list *list;

    list = stack_a->f_element;
    int min;
     int t;
    int next_number;
    int n;
    int i;
    int j;
    int y;

    i = 0;
    j = 0;
    y = 0;
    // printf("number = %d\n", number);
    // printf("lsit->num = %d\n", list->num );
 
    // printf("min =  number - list->num = %d - %d\n",number, list->num);
    min =  number - list->num ;
    if (min < 0)
        min = min * -1;
    next_number = list->num;
   // printf("mins = %d\n", min);
    while(y < p)
    {
        // printf("n = %d\n", n);
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
            //printf("min = %d \n", next_number);
        }
        i++;
        y++;
       // printf("k");
    }
  ////  i = 0;
    //find_number_of_moves(stack_a, next_number);

//     while(i < j)
//     {
//         rotate(stack_a, "ra");
//         i++;
//    // stack_a->f_element = stack_a->f_element->next;
//     }
   // print_stack(stack_a->f_element);
    //printf("hh ======%d\n",stack_a->f_element->num);
    return(next_number);
}

void sort_others(t_stack *stack_a, t_stack *stack_b, t_sorted *sort)
{
    int index;
    int i;
    int j;
    t_list *lst;
  //  lst = stack_a->f_element;
    int min;

    i = 0;
    j = 0;
    int k;
    int min_b;
    int s;
    s = 0;
    min = sort->sorted[0];
    //printf("min = %d \n", min);
     //push(stack_a, stack_b, "pb");
     //min_b = stack_b->f_element->num;
     //printf("min b = %d\n", min_b);
     k = 0;

    while(i < sort->length - 1)
    {
        //lst = stack_a->f_element;
    //
         if(stack_a->f_element->num <= sort->sorted[50])
         {
             
            //  if(stack_a->f_element->num  < min_b)
            //      min_b = stack_a->f_element->num;
            // if(stack_b->f_element)
            // {
            //     j = find_next_number_in_stack_a(stack_b, stack_a->f_element->num);
            //     if(stack_b->f_element->num < stack_a->f_element->num)
            //     {
            //         push(stack_a, stack_b, "pb");
            //         swap(stack_b, "sb");
            //     }
            //     else
            //     {
            //       push(stack_a, stack_b, "pb");
            //     }
            // }
            // else
            // {
                push(stack_a, stack_b, "pb");
           // }
            k++;
            //swap(stack_b, "sb");
         }
                   
        else
         {
            //  if(stack_a->f_element->num  < min_b)
            //      min_b = stack_a->f_element->num;
            rotate(stack_a, "ra");
    //        // swap(stack_b, "sb");
         }
    
      /*  if(stack_a->f_element->num < sort->middle ||stack_a->f_element->num < sort->sorted[75] )
        {
            push(stack_a, stack_b, "pb");
            k++;
        }
        else
        {
              rotate(stack_a, "ra");
        }*/
       // find_number_of_moves(stack_a, sort->sorted[s]);
        //push(stack_a, stack_b , "pb");
        //s++;
      // push(stack_a, stack_b, "pb");
        i++;
    }
    i = 0;

    while(i < 50)
    {
        //lst = stack_a->f_element;
    //
         if(stack_b->f_element->num <= sort->sorted[25])
         {
             
            //  if(stack_a->f_element->num  < min_b)
            //      min_b = stack_a->f_element->num;
            // if(stack_b->f_element)
            // {
            //     j = find_next_number_in_stack_a(stack_b, stack_a->f_element->num);
            //     if(stack_b->f_element->num < stack_a->f_element->num)
            //     {
            //         push(stack_a, stack_b, "pb");
            //         swap(stack_b, "sb");
            //     }
            //     else
            //     {
            //       push(stack_a, stack_b, "pb");
            //     }
            // }
            // else
            // {
                push(stack_b, stack_a, "pa");
           // }
            k++;
            //swap(stack_b, "sb");
         }
                   
        else
         {
            //  if(stack_a->f_element->num  < min_b)
            //      min_b = stack_a->f_element->num;
            rotate(stack_b, "rb");
    //        // swap(stack_b, "sb");
         }
    
      /*  if(stack_a->f_element->num < sort->middle ||stack_a->f_element->num < sort->sorted[75] )
        {
            push(stack_a, stack_b, "pb");
            k++;
        }
        else
        {
              rotate(stack_a, "ra");
        }*/
       // find_number_of_moves(stack_a, sort->sorted[s]);
        //push(stack_a, stack_b , "pb");
        //s++;
      // push(stack_a, stack_b, "pb");
        i++;
    }

        i = 0;

    while(i < 25)
    {
        //lst = stack_a->f_element;
    //
        //  if(stack_b->f_element->num <= sort->sorted[25])
        //  {
             
            //  if(stack_a->f_element->num  < min_b)
            //      min_b = stack_a->f_element->num;
            // if(stack_b->f_element)
            // {
              //  j = find_next_number_in_stack_a(stack_b, stack_a->f_element->num);
                if(stack_b->f_element->num < j)
                {
                    push(stack_b, stack_a, "pa");
                 
                }
                else
                {
                  push(stack_b, stack_a, "pa");
                     swap(stack_b, "sb");
                }
            // }
            // else
            // {
               // push(stack_b, stack_a, "pa");
           // }
            k++;
            //swap(stack_b, "sb");
       //  }
                   
    //     else
    //      {
    //         //  if(stack_a->f_element->num  < min_b)
    //         //      min_b = stack_a->f_element->num;
    //         rotate(stack_b, "rb");
    // //        // swap(stack_b, "sb");
    //      }
    
      /*  if(stack_a->f_element->num < sort->middle ||stack_a->f_element->num < sort->sorted[75] )
        {
            push(stack_a, stack_b, "pb");
            k++;
        }
        else
        {
              rotate(stack_a, "ra");
        }*/
       // find_number_of_moves(stack_a, sort->sorted[s]);
        //push(stack_a, stack_b , "pb");
        //s++;
      // push(stack_a, stack_b, "pb");
        i++;
    }
    //i = k;
    //  find_number_of_moves(stack_b, min_b);
    //  rotate(stack_b,"rb");
    printf("ops = %d\n", stack_a->max + stack_b->max);
    printf("\n%d",sort->sorted[75]);
    // k = sort->length - 4;
    // push(stack_a, stack_b, "pb");
    // while(i < sort->length - 4)
    // {
    //     j = find_next_number_in_stack_a(stack_a, stack_b->f_element->num);
    // }

    //push(stack_a,   stack_b, "pb");
    // push(stack_a, stack_b, "pb");
    // push(stack_a,   stack_b, "pb");
    // push(stack_a, stack_b, "pb");
    // push(stack_a,   stack_b, "pb");
    //    push(stack_a,   stack_b, "pb");
//     printf("stack a == \n");
// printf("stack_B \n");


//    i = 0;
//    j = 0;
   // sort_3_nums(stack_a);
    //printf("middle = %d\n",sort->middle);
     //  printf("stack b == \n");
  // print_stack(stack_b->f_element);
//     printf("nn === %d \n", stack_b->f_element->num);
    //printf("%d", find_next_number_in_stack_a(stack_a, stack_b->f_element->num));
    // int c;
    // c = 2;  
   // i = i + 1;
   //  i = i / 2 + 1;
  // k = i;
//   int o;
//   o = k;
//     while(k)
//     {
//         j = find_next_number_in_stack_a(stack_b, stack_a->f_element->num);
//        // printf("n ======== %d\n",j);
//         // printf("crrnt ======== %d\n",stack_a->f_element->num);

//        if(stack_b->f_element->num < j)
//        {
//              push(stack_b, stack_a, "pa");
//             swap(stack_a, "sa");
//        }
//            // push(stack_b, stack_a, "pa");
//        else
//         {
//             push(stack_b, stack_a, "pa");
//            // swap(stack_a, "sa");
//         }
//         //rotate(stack_a, "ra");
//        //  printf("STACK A \n"); 
//        // print_stack(stack_a->f_element);
//        // printf("\n");
//         // while(stack_a->f_element->num != min)
//         // {
//         //     rotate(stack_a, "ra");
//         // //printf("ra \n");
//         //     // stack_a->f_element = stack_a->f_element->next;
//         // }      
//         printf("ops = %d\n", stack_a->max + stack_b->max);
//         k--;
//     }

    //find_number_of_moves(stack_a, min);
   // printf("%d", stack_a->max + stack_b->max);

    // while(stack_a->f_element->num != sort->middle)
    // {
    //     rotate(stack_a, "ra");
    // }
    // rotate(stack_a, "ra");
   /* 
   TODO : UNCOOMMENT LATER
    int r;
    r = 0;
    int l;
    k = 0;
    push(stack_a, stack_b, "pb");
    while(r < 49)
    {
        if(stack_a->f_element->num < sort->sorted[75])
        {
            push(stack_a, stack_b, "pb");
            k++;
        }
        else
        {
            rotate(stack_a, "ra");
        }
        r++;
    }
    r = 0;
    int m;
    m = k;
    while(r < k + 1)
    {
        //j = find_next_number_in_stack_a(stack_b, stack_a->f_element->num);
        j = find_next_number_in_stack_a(stack_b, stack_a->f_element->num);
        if(stack_a->f_element->num < j)
        {
            push(stack_b, stack_a, "pa");
            swap(stack_a, "sb");
        }
        else
        {
            push(stack_b, stack_a, "pa");
         
        }
        r++;
        m--;
    }
    print_stack(stack_b->f_element);
   // print_stack(stack_a->f_element);
 

 // int r;
    r = 0;
   // int l;
    k = 0;
    push(stack_b, stack_a, "pa");
    while(r < 48)
    {
        if(stack_b->f_element->num < sort->sorted[25])
        {
            push(stack_b, stack_a, "pa");
            k++;
        }
        else
        {
            rotate(stack_b, "rb");
        }
        r++;
    }
    r = 0;
  //  int m;
    m = k;
    while(r < k + 1)
    {
        //j = find_next_number_in_stack_a(stack_b, stack_a->f_element->num);
        j = find_next_number_in_stack_a(stack_a, stack_b->f_element->num);
        if(stack_b->f_element->num < j)
        {
            push(stack_a, stack_b, "pa");
            swap(stack_b, "sb");
        }
        else
        {
            push(stack_a, stack_b, "pa");
         
        }
        r++;
        m--;
    }*/
    print_stack(stack_b->f_element);
   printf("ops = %d\n", stack_a->max + stack_b->max);
   // print_stack(stack_a->f_element);
  
    // while(stack_a->f_element->num != min)
    // {
    //     rotate(stack_a, "ra");
    //     //printf("ra \n");
    //    // stack_a->f_element = stack_a->f_element->next;
    // }  
  //  // while(i < 2)
    // {
    //     index = find_index(sorted, stack_a->f_element->num);
    //     printf("index =%d", index);
    //     if(index == 0)
    //     {
    //         push(stack_b, stack_a, "pa");
    //         i++;
    //         continue ;
    //     }
    //     if(index == 4)
    //     {
    //          push(stack_b, stack_a, "pa");
    //          rotate(stack_a, "ra");
    //          i++;
    //          continue ;
    //     }
    //     j = 0;
    //     while(j < index)
    //     {
    //        rotate(stack_a, "ra"); 
    //        j++; 
    //     }
    //     push(stack_b, stack_a, "pa");
    //     i++;   
    // }
}


void sort_5_nums(t_stack *stack_a, t_stack *stack_b, t_sorted *sort)
{
    // push(stack_a, stack_b, "pb");
    // push(stack_a,   stack_b, "pb");
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