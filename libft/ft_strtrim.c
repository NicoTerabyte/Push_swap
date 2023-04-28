/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:17:29 by lnicoter          #+#    #+#             */
/*   Updated: 2023/01/23 17:21:20 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (start <= end && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (end >= start && ft_strchr(set, s1[end]) != NULL)
		end--;
	result = (char *) malloc (sizeof(*s1) * (end - start + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (start <= end)
		result[i++] = s1[start++];
	result[i] = 0;
	return ((char *)result);
}
