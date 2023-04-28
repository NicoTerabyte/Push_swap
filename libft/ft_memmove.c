/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:55:23 by lnicoter          #+#    #+#             */
/*   Updated: 2023/01/21 18:49:53 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp;
	unsigned char		*dest;

	tmp = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (!dest && !tmp)
		return (dest);
	if (dest > tmp && dest < tmp + len)
	{
		while (len-- > 0)
			dest[len] = tmp[len];
	}
	else
		while (len-- > 0)
			*dest++ = *tmp++;
	return (dst);
}
