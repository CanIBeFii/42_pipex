/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:05:07 by fialexan          #+#    #+#             */
/*   Updated: 2022/12/22 17:13:03 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	i;

	dst_size = 0;
	i = 0;
	while (dest[dst_size] && dst_size < size)
		dst_size++;
	while ((dst_size + i + 1) < size && src[i])
	{
		dest[i + dst_size] = src[i];
		i++;
	}
	if (dst_size < size)
		dest[dst_size + i] = '\0';
	return (dst_size + ft_strlen(src));
}
