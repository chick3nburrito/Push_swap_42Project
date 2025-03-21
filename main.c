#include "push_swap.h"

void	new_node(int value, t_stack **a)
{
	t_stack *new;
	new = (t_stack *) malloc (sizeof(t_stack));
	new->value = value;
	new->next = NULL;
	node_add_back(new, a);
}


void free_stack(t_stack **a)
{
    t_stack *temp;

    while (*a)
    {
        temp = *a;
        *a = (*a)->next;
        free(temp);
    }
}

void handle(char **arv, t_stack **a)
{
    char **tmp;
    int i  = 1;
    int x;

    while (arv[i])
    {
        tmp = ft_split(arv[i], ' ');

        if (!tmp || !tmp[0])
            exit((write(1, "Error\n", 6), free_table(tmp), free_stack(a), 1));

        x = 0;
        while (tmp[x])
        {
            if (string(tmp[x]))
		exit((write(1, "Error\n", 6), free_table(tmp), free_stack(a), 1));

            new_node(ft_atoi(tmp[x++]), a);
        }
	free_table(tmp);
        i++;
    }
	if(duplication(*a))
		exit((write(1, "Error\n", 6),  free_stack(a), 1));
}

int main(int arc, char **arv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if(arc >= 2)
	{
		handle(arv, &a);
		sort(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);

	return (0);
}
