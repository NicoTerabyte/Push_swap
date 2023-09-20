/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:04:36 by lnicoter          #+#    #+#             */
/*   Updated: 2023/05/23 10:19:02 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_types(const char *str, int i, va_list arg)
{
	if (str[i] == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (str[i] == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (str[i] == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	if (str[i] == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (str[i] == '%')
		return (ft_putchar('%'));
	if (str[i] == 'p')
		return (ft_address_print(va_arg(arg, unsigned long),
				"0123456789abcdef"));
	if (str[i] == 'X')
		return (ft_hex_putnbr(va_arg(arg, int),
				"0123456789ABCDEF"));
	if (str[i] == 'x')
		return (ft_hex_putnbr(va_arg(arg, int), "0123456789abcdef"));
	if (str[i] == 'u')
		return (ft_putnbr_unsigned(va_arg(arg, int)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += check_types(str, i + 1, arg);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
