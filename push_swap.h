/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamdjar <bamdjar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:27:07 by bamdjar           #+#    #+#             */
/*   Updated: 2025/03/21 22:55:39 by bamdjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				rank;
	bool			up_med;
	int				cost_to_top;
	int				cost_to_target;
	int				total_cost;
	bool			best_choice;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

void	swap(t_stack **top);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	node_add_back(t_stack *new, t_stack **top);
void	push_in_stack(t_stack **stack_2, t_stack **stack_1);
void	pa(t_stack **stack_2, t_stack **stack_1);
void	pb(t_stack **stack_2, t_stack **stack_1);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_b, t_stack **stack_a);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_2, t_stack **stack_1);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_2, t_stack **stack_1);

int		stack_len(t_stack *top);
t_stack	*ft_last(t_stack *top);
void	free_stack(t_stack **a);
void	assign_indices(t_stack **top);
void	assign_median(t_stack *top);
t_stack	*best_price(t_stack *top);
void	costing(t_stack *b, t_stack *a, int len_a);
void	merge(t_stack **a, t_stack **b);

void	sort(t_stack **top, t_stack **b);
void	sort_three(t_stack **top);
void	sort_five(t_stack **top, t_stack **b);
void	sort_more(t_stack **top, t_stack **b);

int		duplication(t_stack *top);
int		string(const char *str);

long	ft_atoi(const char *str);
void	free_table(char **table);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

bool	check_sort(t_stack *top);
void	assign_ranks(t_stack **top);
t_stack	*smallest(t_stack **stack);
void	assign_target(t_stack *b, t_stack *a);

#endif
