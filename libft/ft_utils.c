/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:21:09 by lnicoter          #+#    #+#             */
/*   Updated: 2023/03/29 15:24:19 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	cifre;

	cifre = 0;
	if (nb == -2147483648)
		return(ft_putstr("-2147483648"));
	else if (nb == 2147483647)
		return(ft_putstr("2147483647"));
	if (nb < 0)
	{
		cifre += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 0 && nb <= 9)
	{
		cifre += ft_putchar(nb + 48);
	}
	else
	{
		cifre += ft_putnbr(nb / 10);
		cifre += ft_putchar((nb % 10) + 48);
	}
	return (cifre);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	cifre;

	cifre = 0;
	if (nb == 4294967295)
		return(ft_putstr("4294967295"));
	if (nb == 0 || nb <= 9)
	{
		cifre += ft_putchar(nb + 48);
	}
	else
	{
		cifre += ft_putnbr_unsigned(nb / 10);
		cifre += ft_putchar((nb % 10) + 48);
	}
	return (cifre);
}
