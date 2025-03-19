#include "push_swap.h"

t_stack	*ft_last(t_stack *top)
{
	if (top == NULL)
		return (NULL);
	while (top->next != NULL)
		top = top->next;
	return (top);
}

long	ft_atoi(const char *str)
{
	long i;
	int sign;

	i = 0;
	sign = 1;

	while(*str == ' ' || ((*str == '\t' && *str == '\r')) )
		str++;

	if(*str == '-' || *str == '+')
	{
		if(*str == '-')
			sign = -1;
		str++;
	}


	while(*str >= '0' && *str <= '9')
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	return (i * sign);
}
