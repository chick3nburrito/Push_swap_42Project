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
	int rank;
	int index;
	struct mystack * next;
}	stack;


char	**ft_split(char const *s, char c);
char 	*ft_substr(char const *s, unsigned int start, size_t len);
long	ft_atoi(const char *str);

int	string(const char *str); //input errors
int	duplication(stack *top);
void	free_table(char **tmp);
void	node_add_back(stack *new, stack **top);

void	quick_sort(stack **top); //sort algo
#endif
