#include "push_swap.h"

int stack_len(t_stack *top)
{
    int len;

    len = 0;
    while (top != NULL)
    {
        len++;
        top = top->next;
    }
    return len;
}

bool check_sort(t_stack *top)
{
    while (top && top->next != NULL)
    {
        if (top->value > top->next->value)
            return false;
        top = top->next;
    }
    return true;
}

void assign_indices(t_stack **top)
{
	t_list *current;
	int i;

	current = *top;
	i = 0;
	while(current)
	{
		current->index = i;
		current  = temp->next;
		i++;
	}
}
void    assign_ranks(t_stack **top)
{
	t_stack *current;
	t_stack *tmp;
	int	rank;

	current = *top;
	while(current)
	{
		rank = 1;
		tmp = *current;
		while(tmp)
		{
			if(current->value > tmp->value)
				rank++;
			tmp = tmp->next;
		}
		current->rank = rank;
		current = current->next;
	}
}
















}
