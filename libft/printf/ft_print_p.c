/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:39:33 by didimitr          #+#    #+#             */
/*   Updated: 2025/01/30 14:16:32 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_p(void *p)
{
	unsigned long int	i;

	i = (unsigned long int)p;
	if (!p)
		return (ft_print_s("(nil)"));
	ft_print_s("0x");
	return (ft_print_x(i) + 2);
}
