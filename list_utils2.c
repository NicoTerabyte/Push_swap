/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:57:40 by lnicoter          #+#    #+#             */
/*   Updated: 2023/04/22 16:18:17 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_beta.h"

int	list_size(t_node *stack)
{
	int	size;
	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	sorter(t_node **stack_a, t_node **stack_b)
{
	if (list_size(*stack_a) == 3)
		three_sorting(stack_a);
	else if (list_size(*stack_a) == 5)
		sort_five_num(stack_a, stack_b);
}
