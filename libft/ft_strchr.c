/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:38:01 by didimitr          #+#    #+#             */
/*   Updated: 2024/11/05 13:38:01 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	const char	*p;

	p = str;
	while (1)
	{
		if (*p == (char)c)
			return ((char *)p);
		if (*p == '\0')
			break ;
		p++;
	}
	return (NULL);
}
