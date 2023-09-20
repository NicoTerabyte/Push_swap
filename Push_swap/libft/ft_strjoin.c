/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:14:49 by lnicoter          #+#    #+#             */
/*   Updated: 2023/01/25 02:08:23 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*final;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	final = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!final)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		final[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		final [i + j] = s2[j];
		j++;
	}
	final[i + j] = '\0';
	return ((char *)final);
}
