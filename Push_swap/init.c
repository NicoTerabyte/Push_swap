/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:21:33 by lnicoter          #+#    #+#             */
/*   Updated: 2023/05/23 10:19:57 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(int ac, char **av, int i, t_stack *stack)
{
	int	j;

	stack->a = (int *)malloc(sizeof(int) * (ac));
	stack->b = (int *)malloc(sizeof(int) * (ac));
	j = 0;
	while (i < ac)
	{
		stack->a[j] = ft_atoi(av[i], stack->a, stack);
		i++;
		j++;
	}
	find_dup(stack->a, j, stack);
	stack->last_a = j;
	stack->last_b = 0;
}

static void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

t_stack	*init(int ac, char **av)
{
	char	**tmp;
	int		len;
	t_stack	*stack;

	tmp = NULL;
	len = 0;
	if (ac == 2)
	{
		tmp = ft_split(av[1], ' ');
		while (tmp[len] != NULL)
			len++;
		stack = malloc(sizeof(t_stack));
		fill_stack(len, tmp, 0, stack);
		free_matrix(tmp);
	}
	else if (ac >= 3)
	{
		stack = malloc(sizeof(t_stack));
		fill_stack(ac, av, 1, stack);
	}
	else
		return (NULL);
	if (stack->last_a == 1)
		ft_exit(stack);
	return (stack);
}

void	three_sorting(t_stack *stack)
{
	if ((stack->a[0] < stack->a[1]) && (stack->a[0] < stack->a[2])
		&& (stack->a[1] > stack->a[2]))
	{
		ft_sa(stack);
		ft_ra(stack);
	}
	else if ((stack->a[0] > stack->a[1]) && (stack->a[0] > stack->a[2])
		&& (stack->a[1] > stack->a[2]))
	{
		ft_sa(stack);
		ft_rra(stack);
	}
	else if ((stack->a[0] < stack->a[1]) && (stack->a[0] > stack->a[2])
		&& (stack->a[1] > stack->a[2]))
		ft_rra(stack);
	else if ((stack->a[0] > stack->a[1]) && (stack->a[0] > stack->a[2])
		&& (stack->a[1] < stack->a[2]))
		ft_ra(stack);
	else if ((stack->a[0] > stack->a[1]) && (stack->a[0] < stack->a[2])
		&& (stack->a[1] < stack->a[2]))
		ft_sa(stack);
}

int	ft_sorter(t_stack *stack)
{
	if (!check_sorted_asc(stack->a, stack->last_a))
	{
		if (stack->last_a == 2)
			ft_sa(stack);
		else if (stack->last_a == 3)
			three_sorting(stack);
		else
			quick_sort_a(stack, stack->last_a, 0);
	}
	return (0);
}
