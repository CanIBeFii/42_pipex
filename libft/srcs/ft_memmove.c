/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:01:46 by fialexan          #+#    #+#             */
/*   Updated: 2022/12/22 17:13:03 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp;
	size_t		i;

	tmp = (char *)src;
	if ((char *)dst < tmp)
	{
		i = -1;
		while (++i < len)
			*(char *)(dst + i) = *(tmp + i);
	}
	else if ((char *)dst > tmp)
	{
		i = len;
		while (i > 0)
		{
			*(char *)(dst + i - 1) = *(tmp + i - 1);
			i--;
		}
	}
	return (dst);
}
