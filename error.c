/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamdjar <bamdjar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:52:12 by bamdjar           #+#    #+#             */
/*   Updated: 2025/03/21 22:56:24 by bamdjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplication(t_stack *top)
{
	int	*values;
	int	valuecount;
	int	i;

	values = (int *)malloc(500 * sizeof(int));
	if (values == NULL)
		return (0);
	valuecount = 0;
	while (top != NULL)
	{
		i = 0;
		while (i < valuecount)
		{
			if (values[i++] == top->value)
				return (free(values), 1);
		}
		values[valuecount++] = top->value;
		top = top->next;
	}
	free(values);
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
