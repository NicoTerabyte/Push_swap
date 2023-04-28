/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:19:28 by lnicoter          #+#    #+#             */
/*   Updated: 2023/03/29 15:24:36 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_putnbr(unsigned int nb, const char *s)
{
	int	i;

	i = 0;
	if (nb >= 16)
		i += ft_hex_putnbr(nb / 16, s);
	i += ft_putchar(s[nb % 16]);
	return (i);
}

static int	ft_address(unsigned long nb, const char *s)
{
	int	i;

	i = 0;
	if (nb >= 16)
		i += ft_address(nb / 16, s);
	i += ft_putchar(s[nb % 16]);
	return (i);
}

int	ft_address_print(unsigned long point, const char *s)
{
	int	i;

	i = 2;
	ft_putchar('0');
	ft_putchar('x');
	i += ft_address(point, s);
	return (i);
}
