/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:52:49 by lnicoter          #+#    #+#             */
/*   Updated: 2023/05/02 17:59:56 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap_beta.h"

// Funzione per calcolare la LIS L'ORIGINALE
/*static int *lis(int *arr, int n, int* len)
{
	int	i;
	int	j;
	int	max;
	int	*lis;
	int	*prev;
	int	*result;

	max = 0;
	lis = (int *) malloc(n * sizeof(int));
	prev = (int *) malloc(n * sizeof(int));
	i = -1;
	while (++i < n)
	{
		lis[i] = 1;
		prev[i] = -1;
		j = -1;
		while (++j < i)
		{
			if (arr[j] < arr[i] && lis[j] + 1 > lis[i])
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
		}
		if (lis[i] > lis[max])
		{
			max = i;
		}
	}

	*len = lis[max];
	result = (int*) malloc(*len * sizeof(int));
	i = max;
	j = *len - 1;
	while (i >= 0)
	{
		result[j] = arr[i];
		i = prev[i];
		j--;
	}
	free(lis);
	free(prev);
	return (result);
}*/

/*
allocate_int_array: funzione di utilità per allocare un array di interi.

initialize_arrays: inizializza gli array lis e prev.

update_lis_and_prev: aggiorna gli array lis e prev per l'indice i in base all'indice j.

find_max_lis_index: trova l'indice dell'elemento con il valore massimo in lis.

get_lis_result: recupera il risultato LIS dall'array arr e dall'array prev.

lis: la funzione principale, che chiama le altre funzioni per eseguire il calcolo.
*/

static int	*allocate_int_array(int size)
{
	return ((int *)malloc(size * sizeof(int)));
}

static void	initialize_arrays(int *lis, int *prev, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		lis[i] = 1;
		prev[i] = -1;
	}
}

static void update_lis_and_prev(int* lis, int* prev, int* arr, int i, int j)
{
	if (arr[j] < arr[i] && lis[j] + 1 > lis[i])
	{
		lis[i] = lis[j] + 1;
		prev[i] = j;
	}
}

static int find_max_lis_index(int* lis, int n)
{
	int	max;
	int	i;

	i = -1;
	max = 0;
	while (++i < n)
	{
		if (lis[i] > lis[max])
		{
			max = i;
		}
	}
	return (max);
}

static int	*get_lis_result(int *arr, int *prev, int max_index, int lis_len)
{
	int	*result;
	int	i;
	int	j;

	result = allocate_int_array(lis_len);
	i = max_index;
	j = lis_len - 1;
	while (i >= 0)
	{
		result[j] = arr[i];
		i = prev[i];
		j--;
	}
	return (result);
}

static int	*lis(int *arr, int n, int *len)
{
	int	*lis;
	int	*prev;
	int	i;
	int	j;
	int max_index;
	int *result;

	lis = allocate_int_array(n);
	prev = allocate_int_array(n);
	i = -1;
	initialize_arrays(lis, prev, n);
	while (++i < n)
	{
		j = -1;
		while (++j < i)
		{
			update_lis_and_prev(lis, prev, arr, i, j);
		}
	}
	max_index = find_max_lis_index(lis, n);
	*len = lis[max_index];
	result = get_lis_result(arr, prev, max_index, *len);
	free(lis);
	free(prev);
	return (result);
}

// Funzione per stampare un array di interi
// static void print_array(int arr[], int n)
// {
// 	int	i;
// 	for (i = 0; i < n; i++)
// 	{
// 		printf("%d ", arr[i]);
// 	}
// 	printf("\n");
// }

/*prego il dio che funzioni*/

static void	push_lis(t_node **stack_a, t_node **stack_b, int *lis_seq)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (lis_seq[size])
		size++;
	size--;
	while (lis_seq[i])
	{
		if (i == size)
			break;
		while (lis_seq[i] != (*stack_a)->data)
		{
			ft_pb(stack_a, stack_b);
		}
		ft_ra(stack_a);
		i++;
	}
	while (list_size(*stack_a) != size)
		ft_pb(stack_a, stack_b);
}
/*note:
fino ad ora la funzione worka come dovrebbe
senza però aver implementato la funzione lis
speriamo bene...

aggiornamento:
con la funzione lis per ora tutto va bene bisonga implementare
il push nello stack b l'idea c'è l'ho però mi aveva dato problemi...
vediamo se funziona.

Aggiornamento del giorno dopo:
io coglione ho gestito male la memoria in find_dup e voila bordello
per fortuna sembra tutto risolto
ovviamente aveva qualche problema di allocazione anche la funzione
che faceva la LIS questa qua sotto
*/
void	lets_try(t_node **stack_a, t_node **stack_b)
{
	int	*arr;
	int	n;
	int	len;
	int	*lis_seq;
	int	i;
	t_node	*tmp;

	tmp = *stack_a;
	n = list_size(*stack_a) - 1;
	i = 0;
	arr = (int *)malloc(n * sizeof(int) + 1);

	while (i <= n)
	{
		arr[i] = tmp->data;
		i++;
		tmp = tmp->next;
	}
	lis_seq = lis(arr, n, &len);
	push_lis(stack_a, stack_b, lis_seq);
	free(lis_seq);
	free(arr);
}
