#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct mystack
{
	int value;
	int index;
	int rank;
	struct mystack * next;
	struct mystack * target;
}	t_stack;


char	**ft_split(char const *s, char c);
char 	*ft_substr(char const *s, unsigned int start, size_t len);
long	ft_atoi(const char *str);

int	string(const char *str); //input errors
int	duplication(t_stack *top);
void	free_table(char **tmp);
void	node_add_back(t_stack *new, t_stack **top);
t_stack	*ft_last(t_stack *top);
t_stack  *smallest(t_stack **stack);

void	assign_indices(t_stack **top);
void    assign_ranks(t_stack **top);
void    assign_target(t_stack *b, t_stack *a);
void	sort(t_stack **top, t_stack **b); //sort algo

int	stack_len(t_stack *top);
bool	check_sort(t_stack *top);

void    ra(t_stack **stack);//instructions
void    rb(t_stack **stack);
void    rr(t_stack **stack_2, t_stack **stack_1);
void    rra(t_stack **stack);
void    rrr(t_stack **stack_2, t_stack **stack_1);
void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void    ss(t_stack **stack_b, t_stack **stack_a);
void    pa(t_stack **stack_2, t_stack **stack_1);
void    pb(t_stack **stack_2, t_stack **stack_1);
void    push_in_stack(t_stack **stack_2, t_stack **stack_1);

void	swap(t_stack **top);
void    rotate(t_stack **stack);
void    reverse_rotate(t_stack **stack);

void    sort_three(t_stack **a);	//algo
void    sort_five(t_stack **a, t_stack **b);

#endif
