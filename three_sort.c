/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:42:33 by lnicoter          #+#    #+#             */
/*   Updated: 2023/04/12 14:53:56 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap_beta.h"

void	three_sorting(t_node **stack_a)
{
	t_node	*middle;
	t_node	*prev;
	t_node	*after;

	prev = *stack_a;
	middle = prev->next;
	after = middle->next;

	if (prev->data > middle->data && prev->data < after->data)
		ft_sa(stack_a);
	else if (prev->data > middle->data && middle->data > after->data)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (prev->data > middle->data && prev->data > after->data && middle->data < after->data)
		ft_ra(stack_a);
	else if (prev->data < middle->data && middle->data > after->data && prev->data < after->data)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (prev->data < middle->data && prev->data > after->data)
		ft_rra(stack_a);
	return ;
}

