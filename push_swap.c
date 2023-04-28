/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:22:32 by lnicoter          #+#    #+#             */
/*   Updated: 2023/04/28 00:51:44 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_beta.h"

// funzione per cercare un valore numerico all'interno della nostra lista
int	find_data_list(t_node **first, int find)
{
	// creiamo un valore di tipo t_list per
	// scorrere la nostra lista partendo dal primo valore
	t_node	*current;

	current = *first;
	while (current != NULL)
	{
		if (current->data == find)
			return (1);
		current = current->next;
	}
	return (0);
}



// MAIN FOR THE NEW FUNCTIONS
int main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_all(&stack_a, ac, av);
	if (list_size(stack_a) == 3)
		three_sorting(&stack_a);
	else if (list_size(stack_a) == 5)
		sort_five_num(&stack_a, &stack_b);
	else
		lets_try(&stack_a, &stack_b);
	//list_display(stack_a);
	return (0);
}

