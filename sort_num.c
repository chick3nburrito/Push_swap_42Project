#include "push_swap.h"

void    sort_three(t_stack **a)
{
    int top = (*a)->value;
    int mid = (*a)->next->value;
    int bot = (*a)->next->next->value;

    if (top > mid && mid < bot && top < bot)
        sa(a);
    else if (top > mid && mid > bot)
    {
        sa(a);
        rra(a);
    }
    else if (top > mid && mid < bot)
        ra(a);
    else if (top < mid && mid > bot && top < bot)
    {
        rra(a);
        sa(a);
    }
    else if (top < mid && mid > bot)
        rra(a);
}
void    sort_five(t_stack **a, t_stack **b)
{
    while (stack_len(*a) > 3)
    {
        if ((*a)->rank == 1 || (*a)->rank == 2)
            pb(a, b);
        else
            ra(a);
    }
    sort_three(a);
    pa(a, b);
    pa(a, b);
    if (!check_sort(*a))
        sa(a);
}
