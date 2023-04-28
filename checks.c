/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:06:40 by lnicoter          #+#    #+#             */
/*   Updated: 2023/04/26 12:07:02 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_beta.h"

int	find_dup(t_node *a, int ac)
{
	int found;
	int *numbers;
	int i;
	int j;

	numbers = (int *)calloc(ac, sizeof(int));
	if (!numbers)
		return (0);
	found = 0;
	i = 0;
	while (a)
		numbers[i++] = a->data, a = a->next;
	i = -1;
	while (numbers[++i])
	{
		j = i;
		while (++j < ac && found != 1)
			if (numbers[i] == numbers[j])
				found = 1;
	}
	free(numbers);
	return (found);
}

void	check_one_arg(char *argv, t_node **stack_a, int argc)
{
	int		i;
	char	**split;

	split = ft_split(argv, ' ');
	if (!split)
		exit(1);
	i = 0;
	while (split[i])
	{
		list_insert(stack_a, ft_atoi(split[i]));
		i++;
	}
}

int	ft_checksorted(t_node *stack_a)
{
	int	i;

	i = stack_a->data;
	while (stack_a)
	{
		if (i > stack_a->data)
			return (1);
		i = stack_a->data;
		stack_a = stack_a->next;
	}
	return (0);
}
void	check_all(t_node **stack_a, int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 2)
		check_one_arg(av[1], stack_a, ac);
	else if (ac > 2)
	{
		while (i < ac)
			list_insert(stack_a, ft_atoi(av[i++]));
	}
	else
		ft_error("Not enough arguments");
	if (find_dup(*stack_a, ac) == 1)
		ft_error("Found dup");
	if (!ft_checksorted(*stack_a))
		exit(1);
}
