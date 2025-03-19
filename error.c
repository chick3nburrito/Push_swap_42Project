#include "push_swap.h"

int	duplication(t_stack *top)
{
	int		*values;
	int		valueCount;
	int		duplicateFound;
	int		i;
	int		found;

	values = (int *)malloc(500 * sizeof(int));
	if (values == NULL)
	{
		return (0);
	}
	valueCount = 0;
	duplicateFound = 0;
	while (top != NULL && duplicateFound == 0)
	{
		i = 0;
		found = 0;
		while (i < valueCount && found == 0)
		{
			if (values[i] == top->value)
			{
				duplicateFound = 1;
				found = 1;
			}
			i++;
		}
		if (found == 0)
		{
			values[valueCount] = top->value;
			valueCount++;
		}
		top = top->next;
	}
	free(values);
	if (duplicateFound == 1)
		return (1);
	else
		return (0);
}

static int	limits(const char *s, long num)
{
	num = ft_atoi(s);
	if (num < INT_MIN || num > INT_MAX)
	{
		return (1);
	}
	return (0);
}

static int	sign_dup(const char *str)
{
	while (*str)
	{
		if (*str == '+' || *str == '-')
		{
			if (*(str + 1) == '+' || *(str + 1) == '-' || *(str + 1) == ' '
				|| *(str + 1) == '\0')
				return (1);
		}
		str++;
	}
	return (0);
}

int	string(const char *str)
{
	if (!str || *str == '\0' || (sign_dup(str)) || limits(str, ft_atoi(str)))
		return (1);
	while (*str)
	{
		if (!((*str >= '0' && *str <= '9') || (*str == '-') || (*str == '+')))
			return (1);
		str++;
	}
	return (0);
}
