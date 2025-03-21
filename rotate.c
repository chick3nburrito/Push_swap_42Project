/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamdjar <bamdjar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:52:54 by bamdjar           #+#    #+#             */
/*   Updated: 2025/03/21 22:53:22 by bamdjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_2, t_stack **stack_1)
{
	rotate(stack_1);
	rotate(stack_2);
	write(1, "rr\n", 3);
}

void	rra(t_stack **stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
}

void	rrr(t_stack **stack_2, t_stack **stack_1)
{
	reverse_rotate(stack_1);
	reverse_rotate(stack_2);
	write(1, "rrr\n", 4);
}
