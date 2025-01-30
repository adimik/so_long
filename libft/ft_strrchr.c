/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:39:32 by didimitr          #+#    #+#             */
/*   Updated: 2024/11/05 13:39:32 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*i;
	const char	*last;

	i = str;
	last = NULL;
	while (1)
	{
		if (*i == (char)c)
			last = i;
		if (*i == '\0')
			break ;
		i++;
	}
	if (last != NULL)
		return ((char *)last);
	else
		return (NULL);
}
