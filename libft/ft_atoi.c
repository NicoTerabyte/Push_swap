/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:08:28 by lnicoter          #+#    #+#             */
/*   Updated: 2023/04/11 15:28:02 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	atoi_error_handler(int value)
{
	if (value == 1)
	{
		ft_printf("Error\nThe value is not correct you can insert only numbers\n");
		exit(1);
	}
	else
	{
		ft_printf("Error\nOverflow found the program will stop\n");
		exit(1);
	}
}

int	ft_atoi(const char *str)
{
	long long res = 0;
	int sign = 1;
	int i = 0;

	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		res = (str[i++] - '0') + (res * 10);
	if (str[i] != '\0')
		atoi_error_handler(1);
	if ((res > INT_MAX && sign == 1) || (-res < INT_MIN && sign == -1))
		atoi_error_handler(res);
	return (res * sign);
}
