#include "push_swap.h"

void    push_in_stack(t_stack **stack_2, t_stack **stack_1)
{
        t_stack  *first_a;
        t_stack  *first_b;

        if (!*stack_1)
                return ;
        first_a = *stack_1;
        *stack_1 = first_a->next;
        first_b = *stack_2;
        first_a->next = first_b;
        *stack_2 = first_a;
}

void sort(t_stack **top, t_stack **b)
{
	if(!check_sort(*top))
	{
		assign_ranks(top);

		if(stack_len(*top) == 2)
			sa(top);
		else if(stack_len(*top) == 3)
			sort_three(top);
		else if(stack_len(*top) == 5)
			sort_five(top, b);
	}
//	while(!check_sort(*top))
//	{
		assign_indices(top);
		assign_indices(b);
		assign_ranks(b);
		assign_target(*b, *top);
//	}
}
