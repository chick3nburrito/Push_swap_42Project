#include "push_swap.h"

void assign_indices(stack *top)
{
    int i;

    if (!top)
        return;

    i = 0;
    while (top)
    {
        top->index = i;
        i++;
        top = top->next;
    }
}
void	assign_ranks(stack **top, int *values, int len)
{
	stack	*current;
	int		i;

	current = *top;
	while (current)
	{
		i = 0;
		while (i < len)
		{
			if (current->value == values[i])
			{
				current->rank = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}
