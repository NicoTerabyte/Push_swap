/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesthree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 23:35:30 by lnicoter          #+#    #+#             */
/*   Updated: 2023/04/28 04:51:28 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_beta.h"

void	ft_rra(t_node **stack_a)
{
	t_node	*current;
	t_node	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	current = *stack_a;
	while (current->next != NULL)
		current = current->next;
	last = current;
	current = *stack_a;
	while (current->next != last)
	{
		current = current->next;
	}
	current->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1 ,"rra\n", 4);
}

void	ft_rrb(t_node **stack_b)
{
	t_node	*current;
	t_node	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	current = *stack_b;
	while (current->next != NULL)
		current = current->next;
	last = current;
	current = *stack_b;
	while (current->next != last)
	{
		current = current->next;
	}
	current->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write(1 ,"rrb\n", 4);
}

void	ft_rrr(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;
	t_node	*last;

	last = *stack_a;
	temp = *stack_a;
	while (last->next != NULL)
	{
		temp = last;
		last = last->next;
	}
	last->next = *stack_a;
	*stack_a = last;
	temp->next = NULL;
	last = *stack_b;
	temp = *stack_b;
	while (last->next != NULL)
	{
		temp = last;
		last = last->next;
	}
	last->next = *stack_a;
	*stack_a = last;
	temp->next = NULL;
	write(1, "rrr\n", 4);
	return ;
}
