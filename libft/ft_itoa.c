/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:00:59 by lnicoter          #+#    #+#             */
/*   Updated: 2023/01/25 08:55:44 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnumber(long n)
{
	int		i;
	long	faken;

	faken = n;
	i = 1;
	if (faken < 0)
	{
		faken *= -1;
		i++;
	}
	while (faken >= 10)
	{
		faken = faken / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	len;
	char	*str;
	long	longcase;

	longcase = n;
	len = ft_countnumber(longcase);
	str = malloc((len * sizeof(char) + 1));
	if (!str)
		return (NULL);
	if (longcase < 0)
	{
		str[0] = '-';
		longcase *= -1;
	}
	str[len] = '\0';
	len--;
	while (longcase >= 10)
	{
		str[len] = (longcase % 10) + 48;
		longcase /= 10;
		len--;
	}
	if (longcase < 10 && longcase >= 0)
		str[len] = (longcase % 10) + 48;
	return (str);
}
