/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:19:35 by didimitr          #+#    #+#             */
/*   Updated: 2025/01/30 14:17:18 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_symbols(const char *c, va_list arg)
{
	if (*c == 'c')
		return (ft_print_c(va_arg(arg, int)));
	if (*c == 's')
		return (ft_print_s(va_arg(arg, char *)));
	if (*c == 'd' || *c == 'i')
		return (ft_print_d(va_arg(arg, int)));
	if (*c == 'x')
		return (ft_print_x(va_arg(arg, unsigned int)));
	if (*c == 'X')
		return (ft_print_xx(va_arg(arg, unsigned int)));
	if (*c == '%')
		return (ft_print_c('%'));
	if (*c == 'p')
		return (ft_print_p(va_arg(arg, void *)));
	if (*c == 'u')
		return (ft_print_u(va_arg(arg, unsigned int)));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;

	va_start(arg, str);
	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i += (ft_symbols(str, arg));
		}
		else
			i += write(1, str, 1);
		str++;
	}
	va_end(arg);
	return (i);
}
