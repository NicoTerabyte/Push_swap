/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:06:00 by lnicoter          #+#    #+#             */
/*   Updated: 2023/05/23 10:22:22 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(t_stack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->a[0];
	while (++i < stack->last_a - 1)
		stack->a[i] = stack->a[i + 1];
	stack->a[i] = tmp;
	write(1, "ra\n", 3);
	return (1);
}

int	ft_rb(t_stack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->b[0];
	while (++i < stack->last_b - 1)
		stack->b[i] = stack->b[i + 1];
	stack->b[i] = tmp;
	write(1, "rb\n", 3);
	return (1);
}

/*ra and rb at the same time.*/
int	ft_rr(t_stack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->a[0];
	while (++i < stack->last_a - 1)
		stack->a[i] = stack->a[i + 1];
	stack->a[i] = tmp;
	i = -1;
	tmp = stack->b[0];
	while (++i < stack->last_b - 1)
		stack->b[i] = stack->b[i + 1];
	stack->b[i] = tmp;
	write(1, "rr\n", 3);
	return (1);
}
