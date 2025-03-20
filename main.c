#include "push_swap.h"

void	new_node(int value, t_stack **a)
{
	t_stack *new;
	new = (t_stack *) malloc (sizeof(t_stack));
	new->value = value;
	new->next = NULL;
	node_add_back(new, a);
//	printf("pushed %d\n", new->value);

}

void	node_add_back(t_stack *new, t_stack **top)
{
	t_stack	*current;
	if(top == NULL || new == NULL)
		return ;
	if(*top == NULL)
	{
		*top = new;
		return ;
	}
	current =  *top;
	while(current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
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
        {
	    free_table(tmp);
            exit((write(1, "Error\n", 6), free_stack(a), 1));
        }

        x = 0;
        while (tmp[x])
        {
            if (string(tmp[x]))
		exit((write(1, "Error\n", 6), free_table(tmp), free_stack(a), 1));

            new_node(ft_atoi(tmp[x]), a);
            x++;
        }
	free_table(tmp);
        i++;
    }
	if(duplication(*a))
	{
		exit((write(1, "Error\n", 6),  free_stack(a), 1));
	}
}

void free_table(char **table)
{
    int i = 0;

    if (!table)
        return;

    while (table[i])
    {
        free(table[i]);
        i++;
    }
    free(table);
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

	return (0);
}
