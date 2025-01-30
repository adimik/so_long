/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_X.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:38:31 by didimitr          #+#    #+#             */
/*   Updated: 2025/01/30 14:16:57 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_xx(long n)
{
	char	*symbols;
	int		i;

	symbols = "0123456789ABCDEF";
	i = 0;
	if (n < 0)
	{
		i += ft_print_c('-');
		n = -n;
	}
	if (n < 16)
		i += ft_print_c(symbols[n]);
	else
	{
		i += ft_print_xx(n / 16);
		i += ft_print_xx(n % 16);
	}
	return (i);
}
