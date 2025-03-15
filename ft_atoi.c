#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int i;
	int sign;

	i = 0;
	sign = 1;

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
