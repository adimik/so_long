/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:36:36 by didimitr          #+#    #+#             */
/*   Updated: 2024/11/05 14:16:55 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int n)
{
	size_t	size;

	if (n > 0)
		size = 0;
	else
		size = 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	num;
	size_t	size;

	num = (long)n;
	size = get_size(n);
	if (n < 0)
		num *= -1;
	s = (char *)malloc(size + 1);
	if (!s)
		return (NULL);
	s[size--] = '\0';
	while (num > 0)
	{
		s[size--] = num % 10 + '0';
		num = num / 10;
	}
	if (size == 0 && s[1] == '\0')
		s[0] = '0';
	else if (size == 0 && s[1])
		s[size] = '-';
	return (s);
}
