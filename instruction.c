/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamdjar <bamdjar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:52:33 by bamdjar           #+#    #+#             */
/*   Updated: 2025/03/21 22:53:22 by bamdjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **top)
{
	t_stack	*first;
	t_stack	*second;

	if (!*top)
		return ;
	if (stack_len(*top) < 2)
		return ;
	first = *top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*top = second;
}

void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*seconde;

	if (!*stack)
		return ;
	if (stack_len(*stack) < 2)
		return ;
	first = *stack;
	seconde = first->next;
	*stack = seconde;
	last = ft_last(*stack);
	last->next = first;
	first->next = NULL;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*new_last;
	t_stack	*first;
	t_stack	*ptr;
	t_stack	*new_first;

	if (!*stack)
		return ;
	if (stack_len(*stack) < 2)
		return ;
	first = *stack;
	new_first = ft_last(*stack);
	ptr = *stack;
	while (ptr->next != new_first)
		ptr = ptr->next;
	new_last = ptr;
	ptr->next = NULL;
	new_first->next = first;
	*stack = new_first;
}

void	node_add_back(t_stack *new, t_stack **top)
{
	t_stack	*current;

	if (top == NULL || new == NULL)
		return ;
	if (*top == NULL)
	{
		*top = new;
		return ;
	}
	current = *top;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
}

void	rrb(t_stack **stack)
{
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
}
