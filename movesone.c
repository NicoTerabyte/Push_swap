/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:57:12 by lnicoter          #+#    #+#             */
/*   Updated: 2023/05/04 11:23:01 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_beta.h"

void	ft_pa(t_node **psa, t_node **psb)
{
	t_node	*tmp;

	if (*psb == NULL)
		return ;
	tmp = *psb;
	*psb = (*psb)->next;
	tmp->next = *psa;
	*psa = tmp;
	write(1, "pa\n", 3);
	return ;
}

void	ft_pb(t_node **psa, t_node **psb)
{
	t_node	*tmp;

	if (*psa == NULL)
		return ;
	tmp = *psa;
	*psa = (*psa)->next;
	tmp->next = *psb;
	*psb = tmp;
	write(1, "pb\n", 3);
	return ;
}

void	ft_sa(t_node **stack_a)
{
	t_node *tmp;
	t_node *tmp2;

	tmp = *stack_a;
	tmp2 = tmp->next;
	*stack_a = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	write(1,"sa\n", 3);
}

void	ft_sb(t_node **stack_b)
{
	t_node *tmp;
	t_node *tmp2;

	tmp = *stack_b;
	tmp2 = tmp->next;
	*stack_b = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	write(1,"sb\n", 3);
}

void	ft_ss(t_node **stack_a, t_node **stack_b)
{
	t_node *tmp;
	t_node *tmp2;

	tmp = *stack_a;
	tmp2 = tmp->next;
	*stack_a = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	tmp = NULL;
	tmp2 = NULL;
	tmp = *stack_b;
	tmp2 = tmp->next;
	*stack_b = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	write(1,"ss\n",3);
}
