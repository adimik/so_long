/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/11/05 13:36:55 by didimitr          #+#    #+#             */
/*   Updated: 2024/11/05 13:36:55 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;

	if (!dst && !src)
		return (NULL);
	s = src;
	d = dst;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dst);
}
