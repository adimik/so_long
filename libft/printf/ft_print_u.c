/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:40:24 by didimitr          #+#    #+#             */
/*   Updated: 2025/01/30 14:16:40 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_u(unsigned int i)
{
	int	c;

	c = 0;
	if (i < 10)
		c += ft_print_c(i + 48);
	else
	{
		c += ft_print_u(i / 10);
		c += ft_print_u(i % 10);
	}
	return (c);
}
