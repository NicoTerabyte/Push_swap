/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:46:29 by lnicoter          #+#    #+#             */
/*   Updated: 2023/04/22 12:57:24 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_beta.h"

static t_node	*ft_lstlastv2(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

static void	ft_lstadd_backv2(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlastv2 (*lst);
		last->next = new;
	}
}
void	list_display(t_node *p)
{
	ft_printf("\n");
	while (p != NULL)
	{
		ft_printf("|%d|\n⬇⬇⬇\n", p->data);
		p = p->next;
	}
	ft_printf("NULL");
}

void	list_insert(t_node **first, int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
	{
		free(new);
		ft_error("Malloc went badly");
	}
	new->data = data;
	new->next = NULL;
	ft_lstadd_backv2(first, new);
}
