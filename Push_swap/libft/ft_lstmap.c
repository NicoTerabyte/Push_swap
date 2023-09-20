/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:54:54 by lnicoter          #+#    #+#             */
/*   Updated: 2023/01/27 13:30:12 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_list_start;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	temp = lst;
	new_list = ft_lstnew(f(temp->content));
	if (!new_list)
		return (NULL);
	new_list_start = new_list;
	temp = temp->next;
	while (temp)
	{
		new_list->next = ft_lstnew(f(temp->content));
		if (!new_list->next)
		{
			ft_lstclear(&new_list_start, del);
			return (NULL);
		}
		new_list = new_list->next;
		temp = temp->next;
	}
	return (new_list_start);
}
