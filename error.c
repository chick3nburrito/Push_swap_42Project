#include  "push_swap.h"

int	duplication(stack *top)
{
  stack *current = a;
  int *values = (int *)malloc(500 * sizeof(int));
  if (values == NULL) {
   return 0;
  }
  int valueCount = 0;
  int duplicateFound = 0;

  while (current != NULL && duplicateFound == 0)
{
   int i = 0;
   int found = 0;

   while (i < valueCount && found == 0) 
   {
    if (values[i] == current->value)
	{
    	 duplicateFound = 1;
     	found = 1;
        }
    i++;
   }

   if (found == 0) {
    values[valueCount] = current->value;
    valueCount++;
   }

   current = current->next;
  }

  free(values);
  if (duplicateFound == 1)
	return 1;
 else
   return 0;
 }

static int	limits(const char *s, long num)
{
	num = ft_atoi(s);
	if (num < INT_MIN || num > INT_MAX)
	{
		return (1);
	}
	return (0);
}

static int	sign_dup(const char *str)
{
	while(*str)
	{
		if(*str == '+' || *str == '-')
		{
			if (*(str + 1) == '+' || *(str + 1) == '-' || *(str + 1) == ' ' || *(str + 1) == '\0')

                        	return (1);
		}
		str++;
	}
	return 0;
}

int 	string(const char *str)
{
	if(!str || *str == '\0' || (sign_dup(str)) || limits(str, ft_atoi(str)))
		return (1);

	while(*str)
	{
		if(!((*str >= '0' && *str <= '9' ) || (*str == '-') || (*str == '+')))
			return (1);
		str++;
	}

	return (0);
}
