#include "push_swap.h"

int	stack_len(stack *top)
{
	int len;
	len = 0;
	while(top != NULL)
	{
		len++;
		top = top->next;
	}
	return len;
}

bool	check_sort(stack *top)
{
	while(top->next != NULL)
	{
		if(top->value > top->next->value)
			return (false);
		top = top->next;
	}
	return (true);
}

void	fill_values(int *values, stack *top)
{
	int i = 0;
	while(top != NULL)
	{
		values[i] = top->value;
		i++;
		top = top->next;
		printf("pushed to table \n");
	}
}

void	quick_sort(stack **top)
{
	if(check_sort(*top))
		return ;
	int *values;
	values = (int *) malloc (sizeof(int) * (stack_len(*top)));
	if(!values)
		return ;
	fill_values(values, *top);


}
