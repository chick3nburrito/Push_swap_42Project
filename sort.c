#include "push_swap.h"

void sort(t_stack **top)
{
	while(!check_sort(*top))
	{
		assign_indices(top);
		assign_ranks(top);
	}
}
