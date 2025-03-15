#include  "push_swap.h"

const int	sign_dup(const char *str)
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
	if(!str || *str == 0)
		return (1);

	while(*str)
	{
		if((*str >= '0' && *str >= '9' ) || (*str >= '-') || (*str == '+'))
			str++;
		else
			return (1);
		str++;
	}

	return (sign_dup(str));
}
