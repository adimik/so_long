/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:35:28 by didimitr          #+#    #+#             */
/*   Updated: 2025/01/30 14:16:37 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_s(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (ft_print_s("(null)"));
	while (*c)
	{
		i += write(1, c, 1);
		c++;
	}
	return (i);
}
