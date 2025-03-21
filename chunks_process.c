/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamdjar <bamdjar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:52:05 by bamdjar           #+#    #+#             */
/*   Updated: 2025/03/21 22:57:49 by bamdjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_median(t_stack *top)
{
	int	len;

	len = stack_len(top) / 2;
	assign_indices(&top);
	while (top)
	{
		top->up_med = (top->index <= len);
		top = top->next;
	}
}

t_stack	*best_price(t_stack *top)
{
	long	x;
	t_stack	*node;

	if (!top)
		return (NULL);
	x = LONG_MAX;
	node = NULL;
	while (top)
	{
		if (top->total_cost < x)
		{
			x = top->total_cost;
			node = top;
		}
		top = top->next;
	}
	if (node)
		node->best_choice = true;
	return (node);
}

void	costing(t_stack *b, t_stack *a, int len_a)
{
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->cost_to_top = b->index;
		if (!b->up_med)
			b->cost_to_top = len_b - (b->index);
		if (b->target->up_med)
			b->cost_to_target = (b->target->index);
		else
			b->cost_to_target = len_a - (b->target->index);
		if ((b->up_med && b->target->up_med) || (!b->up_med
				&& !b->target->up_med))
		{
			if (b->cost_to_top > b->cost_to_target)
				b->total_cost = b->cost_to_top;
			else
				b->total_cost = b->cost_to_target;
		}
		else
			b->total_cost = b->cost_to_top + b->cost_to_target;
		b = b->next;
	}
}

static void	to_top(t_stack **a, t_stack **b, t_stack *node)
{
	if (node->up_med)
	{
		while (*b != node)
			rb(b);
	}
	else
	{
		while (*b != node)
			rrb(b);
	}
	if (node->target->up_med)
	{
		while (*a != node->target)
			ra(a);
	}
	else
	{
		while (*a != node->target)
			rra(a);
	}
}

void	merge(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = best_price(*b);
	if (!node)
		return ;
	if (node->up_med && node->target->up_med)
	{
		while (node != *b && node->target != *a)
			rr(b, a);
	}
	else if (!node->up_med && !node->target->up_med)
	{
		while (node != *b && node->target != *a)
			rrr(b, a);
	}
	assign_median(*a);
	assign_median(*b);
	to_top(a, b, node);
	pa(a, b);
}
