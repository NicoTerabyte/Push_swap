/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:27:15 by lnicoter          #+#    #+#             */
/*   Updated: 2023/05/23 16:21:15 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_3_a_b(t_stack *stack, int dim)
{
	if (dim == 3 && stack->last_a == 3)
		three_sorting(stack);
	else if (dim == 2)
	{
		if (stack->a[0] > stack->a[1])
			ft_sa(stack);
	}
	else if (dim == 3)
	{
		while (dim != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (dim == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				ft_sa(stack);
			else if (dim == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				dim = when_push(stack, dim, 1);
			else if (stack->a[0] > stack->a[1])
				ft_sa(stack);
			else if (dim++)
				ft_pa(stack);
		}
	}
}

int	partition(int *pivot, int *stack, int dim)
{
	int	*tmp;
	int	i;
	int	j;

	tmp = (int *)malloc(sizeof(int) * dim);
	if (!tmp)
		return (0);
	i = 0;
	j = 0;
	while (i < dim)
		tmp[j++] = stack[i++];
	tmp_sort(tmp, dim);
	*pivot = tmp[dim / 2];
	free(tmp);
	return (1);
}

int	sort_3_b(t_stack *stack, int dim)
{
	if (dim == 1)
		ft_pa(stack);
	else if (dim == 2)
	{
		if (stack->b[0] < stack->b[1])
			ft_sb(stack);
		while (dim--)
			ft_pa(stack);
	}
	else if (dim == 3)
	{
		while (dim || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (dim == 1 && stack->a[0] > stack->a[1])
				ft_sa(stack);
			else if (dim == 1
				|| (dim >= 2 && stack->b[0] > stack->b[1])
				|| (dim == 3 && stack->b[0] > stack->b[2]))
				dim = when_push(stack, dim, 0);
			else
				ft_sb(stack);
		}
	}
	return (0);
}

int	quick_sort_b(t_stack *stack, int dim, int count_r)
{
	int	pivot;
	int	numbers;

	if (!count_r && check_sorted_desc(stack->b, dim) == 1)
		while (dim--)
			ft_pa(stack);
	if (dim <= 3)
	{
		sort_3_b(stack, dim);
		return (1);
	}
	numbers = dim;
	if (!partition(&pivot, stack->b, dim))
		return (0);
	while (dim != numbers / 2)
	{
		if (stack->b[0] >= pivot && dim--)
			ft_pa(stack);
		else if (++count_r)
			ft_rb(stack);
	}
	while (numbers / 2 != stack->last_b && count_r--)
		ft_rrb(stack);
	return (quick_sort_a(stack, numbers / 2 + numbers % 2, 0)
		&& quick_sort_b(stack, numbers / 2, 0));
}

int	quick_sort_a(t_stack *stack, int dim, int count_r)
{
	int	pivot;
	int	numbers;

	if (check_sorted_asc(stack->a, dim) == 1)
		return (1);
	numbers = dim;
	if (dim <= 3)
	{
		quick_sort_3_a_b(stack, dim);
		return (1);
	}
	if (!count_r && !partition(&pivot, stack->a, dim))
		return (0);
	while (dim != numbers / 2 + numbers % 2)
	{
		if (stack->a[0] < pivot && (dim--))
			ft_pb(stack);
		else if (++count_r)
			ft_ra(stack);
	}
	while (count_r--)
		ft_rra(stack);
	return (quick_sort_a(stack, numbers / 2 + numbers % 2, 0)
		&& quick_sort_b(stack, numbers / 2, 0));
	return (1);
}
