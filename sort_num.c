/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamdjar <bamdjar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:53:03 by bamdjar           #+#    #+#             */
/*   Updated: 2025/03/21 22:55:39 by bamdjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		rra(a);
		sa(a);
	}
	else if (top < mid && mid > bot)
		rra(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		if ((*a)->rank == 1 || (*a)->rank == 2)
			pb(b, a);
		else
			ra(a);
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
	if (!check_sort(*a))
		sa(a);
}

static void	chunks_process(t_stack **top, t_stack **b)
{
	float	x;
	float	i;

	x = stack_len(*top) / 4;
	i = x;
	assign_ranks(top);
	while (stack_len(*top) > 3 && !check_sort(*top))
	{
		if ((*top)->rank <= x)
		{
			pb(b, top);
			assign_ranks(top);
		}
		else
			ra(top);
		if (stack_len(*top) == i)
			x += i / 4;
		else
			i = stack_len(*top);
	}
}

void	final_sort(t_stack **a)
{
	t_stack	*smallest_node;
	int		len_a;
	int		index;

	if (check_sort(*a))
		smallest_node = smallest(a);
	index = smallest_node->index;
	len_a = stack_len(*a);
	if (index <= len_a / 2)
	{
		while ((*a)->value != smallest_node->value)
			ra(a);
	}
	else
	{
		while ((*a)->value != smallest_node->value)
			rra(a);
	}
}

void	sort_more(t_stack **top, t_stack **b)
{
	chunks_process(top, b);
	while (stack_len(*b) > 0)
	{
		assign_median(*top);
		assign_median(*b);
		assign_target(*b, *top);
		costing(*b, *top, 0);
		if (!best_price(*b))
			break ;
		merge(top, b);
	}
	final_sort(top);
}
