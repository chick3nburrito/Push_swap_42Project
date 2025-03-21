/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamdjar <bamdjar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:53:10 by bamdjar           #+#    #+#             */
/*   Updated: 2025/03/21 22:53:22 by bamdjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *top)
{
	int	len;

	len = 0;
	while (top != NULL)
	{
		len++;
		top = top->next;
	}
	return (len);
}

bool	check_sort(t_stack *top)
{
	if (!top)
		return (true);
	while (top && top->next != NULL)
	{
		if (top->value > top->next->value)
			return (false);
		top = top->next;
	}
	return (true);
}

void	assign_ranks(t_stack **top)
{
	t_stack	*current;
	t_stack	*tmp;
	int		rank;

	current = *top;
	while (current)
	{
		rank = 1;
		tmp = *top;
		while (tmp)
		{
			if (current->value > tmp->value)
				rank++;
			tmp = tmp->next;
		}
		current->rank = rank;
		current = current->next;
	}
}

t_stack	*smallest(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*small;

	ptr = NULL;
	ptr = *stack;
	small = ptr;
	while (ptr)
	{
		if (ptr->value < small->value)
			small = ptr;
		ptr = ptr->next;
	}
	return (small);
}

void	assign_target(t_stack *b, t_stack *a)
{
	t_stack	*the_target;
	t_stack	*x;
	long	index;

	while (b)
	{
		index = LONG_MAX;
		x = a;
		while (x)
		{
			if (b->value < x->value && x->value < index)
			{
				index = x->value;
				the_target = x;
			}
			x = x->next;
		}
		if (index == LONG_MAX)
			b->target = smallest(&a);
		else
			b->target = the_target;
		b = b->next;
	}
}
