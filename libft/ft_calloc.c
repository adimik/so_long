/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:35:51 by didimitr          #+#    #+#             */
/*   Updated: 2024/11/05 13:35:51 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t size_of_element)
{
	unsigned char	*arr;
	size_t			i;

	if (num_elements != 0 && size_of_element > SIZE_MAX / num_elements)
		return (NULL);
	i = 0;
	arr = malloc(num_elements * size_of_element);
	if (!arr)
		return (NULL);
	while (i < (num_elements * size_of_element))
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)(arr));
}
