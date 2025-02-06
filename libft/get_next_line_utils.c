/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:38:38 by didimitr          #+#    #+#             */
/*   Updated: 2025/02/05 12:34:28 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr2(char const *s, int start, size_t len)
{
	char	*sub;
	size_t	j;

	if (!s)
		return (NULL);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	j = 0;
	if (start < ft_strlen2((char *)s))
	{
		while (j < len && s[start])
			sub[j++] = s[start++];
		sub[j] = '\0';
	}
	return (sub);
}

int	ft_strlen2(char *str)
{
	int	l;

	if (!str)
		return (0);
	l = 0;
	while (str[l])
		l++;
	return (l);
}

int	ft_strchr2(const char *s, int c, int out)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	if (out == 1)
		return (i);
	return (0);
}

char	*ft_strdup2(char *s1)
{
	char	*p;
	int		i;

	p = malloc(ft_strlen2((char *)s1) + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len = ft_strlen2(s1) + ft_strlen2(s2);
	join = malloc(len + 1);
	if (!join)
		return (NULL);
	while (*s1)
		join[i++] = *(s1++);
	while (*s2)
		join[i++] = *(s2++);
	join[i] = '\0';
	return (join);
}
