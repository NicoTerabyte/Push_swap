/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:29:53 by lnicoter          #+#    #+#             */
/*   Updated: 2023/04/28 04:49:19 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_beta.h"

static int	*malloc_doing_array_full(int *a, int **lis, int **index,
										 t_node **stack_a)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	a = (int *)malloc(list_size(*stack_a) * sizeof(int));
	*lis = (int *)malloc(list_size(*stack_a) * sizeof(int));
	*index = (int *)malloc(list_size(*stack_a) * sizeof(int));
	/*Riempio l'array con i valori della lista*/
	printf("Stampa lista temporanea\n");
	list_display(tmp);
	printf("fine stampa\n");
	while (tmp != NULL)
	{
		printf("a[%d] = %d\n", i, tmp->data);
		printf("a[%d] = %d\n", i, a[i]);
		a[i] = tmp->data;
		printf("a[%d] = %d\n numero inserito\n", i, a[i]);
		i++;
		tmp = tmp->next;
	}
	printf("Funzione conclusa\n");
	return (a);
}

static int search_replace (int *lis, int left, int right, int key)
{
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (lis[mid] < key)
			left = mid + 1;
		else
			right = mid;
	}
	lis[left] = key;
	return left;
}

int lis_execution(t_node **stack_a)
{
	int i, j;
    int lis_length;
    int size;
    int *a;
    int *lis;
    int *index;

    a = malloc_doing_array_full(a, &lis, &index, stack_a);
    size = list_size(*stack_a);
    lis_length = 0;
    lis[0] = a[0];
    index[0] = 0;
    for (i = 1; i < size; ++i)
    {
        index[i] = i;
        if (a[i] > lis[lis_length])
        {
            lis_length++;
            lis[lis_length] = a[i];
            index[i] = lis_length;
        }
        else
        {
            j = search_replace(lis, 0, lis_length, a[i]);
            lis[j] = a[i];
            index[i] = j;
        }
    }
    printf("lis: ");
    for (i = 0; i <= lis_length; ++i)
    {
        printf("%d ", lis[i]);
    }
    printf("\n");
    printf("lis_length = %d\n", lis_length + 1);
    printf("lis_index: ");
    for (i = 0; i < size; ++i)
    {
        printf("%d ", index[i]);
    }
    printf("\n");
    return 0;
}
/*
static int	search_replace(int *lis, int left, int right, int key)
{
	int mid;

	for (mid = (left+right)/2; left <= right; mid = (left+right)/2)
	{
		if (lis[mid] > key)
		{
			right = mid - 1;
		}
		else if (lis[mid] == key)
		{
			return mid;
		}
		else if (mid+1 <= right && lis[mid+1] >= key)
		{
			lis[mid+1] = key;
			return mid+1;
		}
		else
		{
			left = mid + 1;
		}
	}
	if (mid == left)
	{
		lis[mid] = key;
		return mid;
	}
	lis[mid+1] = key;
	return mid+1;
}
*/

/*int	lis_execution(t_node **stack_a)
{
	int	i;
	int	lis_length;
	int	size;
	int	*a;
	int	*lis;
	int	*index;

	a = malloc_doing_array_full(a, &lis, &index, stack_a);
	size = list_size(*stack_a);
	lis_length = 0;
	i = 0;
	while (i < list_size(*stack_a))
	{
		printf("valori array a: %d\n",a[i]);
		i++;
	}
	lis[0] = a[0];
	for (i = 1; i < size; ++i)
	{
		lis[i] = INT_MAX;
	}
	for (i = 1; i < size; ++i)
	{
		index[i] = search_replace(lis, 0, i, a[i]);
		if (lis_length < index[i])
		{
			lis_length = index[i];
		}
	}
	printf("lis: ");
	for (i = 0; i < lis_length+1; ++i)
	{
		printf("%d ", lis[i]);
	}
	printf("\n");
	return 0;
}*/



