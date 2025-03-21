#include "push_swap.h"

static void    all(char **result)
{
    char    **current;

    current = result;
    while (*current)
    {
        free(*current);
        current++;
    }
    free(result);
}
static int    allocate(char **result, char const *s, char sep)
{
    char        **result1;
    char const    *tmp;

    result1 = result;
    tmp = s;
    while (*s)
    {
        while (*s == sep)
            s++;
        tmp = s;
        while (*tmp && *tmp != sep)
            tmp++;
        if (tmp > s)
        {
            *result1 = ft_substr(s, 0, tmp - s);
            if (!*result1)
            {
                all(result);
                return(1);
            }
            s = tmp;
            result1++;
        }
    }
    *result1 = NULL;
	return (0);
}


static int	words(char const *str, char c)
{
	int i;
	int in_word;

	i = 0;
	in_word = 0;
	while(*str)
	{
		if(*str == c)
			in_word = 0;
		else
			if(!in_word)
				{
					i++;
					in_word = 1;
				}
		str++;
	}
	return (i);
}

char    **ft_split(char const *s, char c)
{
    char    **result;
    int        size;

    if (!s)
        return (NULL);

    size = words(s, c);
    result = (char **)malloc(sizeof(char *) * (size + 1));
    if (!result)
        return (NULL);
    if(allocate(result, s, c))
	return (NULL);
    return (result);
}
