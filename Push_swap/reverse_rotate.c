/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:05:48 by lnicoter          #+#    #+#             */
/*   Updated: 2023/05/23 10:17:55 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rra(t_stack *stack)
{
	int	len;
	int	tmp;

	tmp = stack->a[stack->last_a - 1];
	len = stack->last_a;
	while (len > 0)
	{
		stack->a[len] = stack->a[len - 1];
		len--;
	}
	stack->a[0] = tmp;
	write(1, "rra\n", 4);
	return (1);
}

int	ft_rrb(t_stack *stack)
{
	int	len;
	int	tmp;

	tmp = stack->b[stack->last_b - 1];
	len = stack->last_b;
	while (len-- > 0)
		stack->b[len] = stack->b[len - 1];
	stack->b[0] = tmp;
	write(1, "rrb\n", 4);
	return (1);
}

/*rra and rrb at the same time.*/
int	ft_rrr(t_stack *stack)
{
	int	len;
	int	tmp;

	tmp = stack->a[stack->last_a - 1];
	len = stack->last_a;
	while (len-- > 0)
		stack->a[len] = stack->a[len - 1];
	stack->a[0] = tmp;
	tmp = stack->b[stack->last_b - 1];
	len = stack->last_b;
	while (len-- > 0)
		stack->b[len] = stack->b[len - 1];
	stack->b[0] = tmp;
	write(1, "rrr\n", 4);
	return (1);
}
