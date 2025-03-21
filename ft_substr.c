/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamdjar <bamdjar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:52:28 by bamdjar           #+#    #+#             */
/*   Updated: 2025/03/21 22:53:22 by bamdjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (len > 0)
	{
		while (src[i] && i < len - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tab;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (malloc(sizeof(char)));
	i = ft_strlen(s + start);
	if (i < len)
	{
		len = i;
	}
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, s + start, len + 1);
	return (tab);
}
