/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movestwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:22:21 by lnicoter          #+#    #+#             */
/*   Updated: 2023/04/28 04:52:35 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_beta.h"
//sono un coglione io avevo messo l'ultimo come primo mentre il comando
//metteva il primo come ultimo non variando la posizione dell'ultimo
void	ft_ra(t_node **stack_a)
{
	t_node	*first;
	t_node	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = *stack_a;
	first = *stack_a;
	while (last->next != NULL)
		last = last->next;
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	write(1 ,"ra\n", 3);
	return ;
}

void	ft_rb(t_node **stack_b)
{
	t_node	*first;
	t_node	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = *stack_b;
	first = *stack_b;
	while (last->next != NULL)
		last = last->next;
	*stack_b = first->next;
	first->next = NULL;
	last->next = first;
	write(1 ,"ra\n", 3);
	return ;
}

void	ft_rr(t_node **stack_a, t_node **stack_b)
{
	t_node	*first;
	t_node	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = *stack_a;
	first = *stack_a;
	while (last->next != NULL)
		last = last->next;
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = *stack_b;
	first = *stack_b;
	while (last->next != NULL)
		last = last->next;
	*stack_b = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rr\n", 3);
	return ;
}
