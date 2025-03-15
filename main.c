#include "push_swap.h"

void	new_node(int value, stack **a)
{
	stack *new;
	new = (stack *) malloc (sizeof(stack));
	new->value = value;
	new->next = *a;
	a = &new;
	printf("pushed %d\n", new->value);
}

void      handle(char **arv, stack **a)
{
	char **tmp;

	tmp = ++arv;
	if(!arv[2])
	{
                tmp = ft_split(tmp[0], ' ');
	}

        while(*tmp)
        {
             if(string(*tmp))
			exit(((write(1, "Error\n", 6)), 1));
                new_node(ft_atoi(*tmp), a);
		*(tmp++);
        }

}

int main(int arc, char **arv)
{
	stack *a;
	stack *b;

	a = NULL;
	b = NULL;
	if(arc >= 2)
	{
		handle(arv, &a);
	}

	return (0);
}
