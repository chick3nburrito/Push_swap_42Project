
#include "push_swap.h"

void    pa(t_stack **stack_2, t_stack **stack_1)
{
        push_in_stack(stack_2, stack_1);
        write(1, "pa\n", 3);
}

void    pb(t_stack **stack_2, t_stack **stack_1)
{
        push_in_stack(stack_2, stack_1);
        write(1, "pb\n", 3);
}

void    sa(t_stack **stack_a)
{
        swap(stack_a);
        write(1, "sa\n", 3);
}

void    sb(t_stack **stack_b)
{
        swap(stack_b);
        write(1, "sb\n", 3);
}

void    ss(t_stack **stack_b, t_stack **stack_a)
{
        swap(stack_a);
        swap(stack_b);
        write(1, "ss\n", 3);
}
