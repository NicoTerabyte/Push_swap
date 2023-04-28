/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:54:32 by lnicoter          #+#    #+#             */
/*   Updated: 2023/04/27 22:52:12 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_beta.h"

int	min_finder_a(t_node *stack_a)
{
	int		pos;
	int		min;
	int		index;

	min = stack_a->data;
	pos = 0;
	index = 0;
	while (stack_a->next != NULL)
	{
		if (min > stack_a->next->data)
		{
			min = stack_a->next->data;
			pos = index + 1;
		}
		stack_a = stack_a->next;
		index++;
	}
	return (pos);
}

int	max_finder_a(t_node *stack_a)
{
	int		pos;
	int		max;
	int		index;

	max = stack_a->data;
	pos = 0;
	index = 0;
	while (stack_a->next != NULL)
	{
		if (max < stack_a->next->data)
		{
			max = stack_a->next->data;
			pos = index + 1;
		}
		stack_a = stack_a->next;
		index++;
	}
	return (pos);
}

static void	push_in_order_min_max(t_node **stack_a, t_node **stack_b)
{
	int		min;
	int		max;
	int		i;

	min = min_finder_a(*stack_a);
	max = max_finder_a(*stack_a);
	i = 0;
	while (i < min)
	{
		ft_ra(stack_a);
		i++;
	}
	ft_pb(stack_a, stack_b);
	i = 1;
	while (i < max - min)
	{

		ft_ra(stack_a);
		i++;
	}
	ft_pb(stack_a, stack_b);
}

static void	push_in_order_max_min(t_node **stack_a, t_node **stack_b)
{
	int		min;
	int		max;
	int		i;

	min = min_finder_a(*stack_a);
	max = max_finder_a(*stack_a);
	i = 0;
	while (i < max)
	{
		ft_ra(stack_a);
		i++;
	}
	ft_pb(stack_a, stack_b);
	i = 1;
	while (i < min - max)
	{
		ft_ra(stack_a);
		i++;
	}
	ft_pb(stack_a, stack_b);
}

void	sort_five_num(t_node **stack_a, t_node **stack_b)
{
	int	max;
	int	min;

	max = max_finder_a(*stack_a);
	min = min_finder_a(*stack_a);
	if (min < max)
		push_in_order_min_max(stack_a, stack_b);
	else
		push_in_order_max_min(stack_a, stack_b);
	three_sorting(stack_a);
	if ((*stack_b)->data > (*stack_b)->next->data)
		ft_sb(stack_b);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_ra(stack_a);
}

