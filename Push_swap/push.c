/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:05:54 by lnicoter          #+#    #+#             */
/*   Updated: 2023/05/23 10:16:40 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pa(t_stack *stack)
{
	int	len;

	len = stack->last_a;
	while (len > 0)
	{
		stack->a[len] = stack->a[len - 1];
		len--;
	}
	stack->last_a++;
	stack->a[0] = stack->b[0];
	len = 1;
	while (len < stack->last_b)
	{
		stack->b[len - 1] = stack->b[len];
		len++;
	}
	stack->last_b--;
	write(1, "pa\n", 3);
	return (1);
}

int	ft_pb(t_stack *stack)
{
	int	len;

	len = stack->last_b;
	while (len > 0)
	{
		stack->b[len] = stack->b[len - 1];
		len--;
	}
	stack->last_b++;
	stack->b[0] = stack->a[0];
	len = 1;
	while (len < stack->last_a)
	{
		stack->a[len - 1] = stack->a[len];
		len++;
	}
	stack->last_a--;
	write(1, "pb\n", 3);
	return (1);
}
