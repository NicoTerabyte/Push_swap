/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phaseone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:54:53 by lnicoter          #+#    #+#             */
/*   Updated: 2023/05/04 16:09:18 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "push_swap_beta.h"

void	countdown(t_node **stack_a, t_node **stack_b, int *distances_a)
{
	int		move_sum;
	int		half_twoA;
	int		counter_b;
	int		i;
	t_node	*tmp_a;
	t_node	*tmp_b;


	i = 0;
	tmp_a = *stack_a;
	tmp_b = *stack_b;
	half_twoA = list_size(*stack_a)/2;
	while (tmp_a)
	{
		while (tmp_b)
		{
			
		}
	}
}

void	calculate_mv(t_node **stack_a, t_node **stack_b)
{
	//calcolo la distanza dalla prima posizione dell'ieasimo elemento nella mia lista
	int		*distances_A; //distanza dalla prima posizione nello stack_a
	int		half_twoA; //questo valore equivale alla meta della grandezza totale del mio stack_a serve per determinare se usare ra o rra
	t_node	*tmp_a; //variabile temporanea per scorrere la lista senza problemi
	int i;

	distances_A = malloc(list_size(*stack_a) * sizeof(int));
	i = 0;
	tmp_a = *stack_a;
	while (tmp_a)
	{
		distances_A[i] = i;
		tmp_a = tmp_a->next;
		i++;
	}
	//! ricordati che per stampare correttamente l'array lo devi fare sempre con i < list_size se no smerda ovunque

}

void	select_num(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	//fase 1 pusho due numeri a caso fatto
	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	//controllo che i ddue valori siano ordinati in maniera discendente
	if ((*stack_b)->next->data > (*stack_b)->data)
		ft_sb(stack_b);
	//fase due calcolo del numero piu cheap
	calculate_mv(stack_a, stack_b);
}
