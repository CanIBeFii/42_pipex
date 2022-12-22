/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:02:25 by fialexan          #+#    #+#             */
/*   Updated: 2022/12/22 17:13:03 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		e;
	char	*str;

	i = 0;
	e = 0;
	str = (void *)s;
	while (str[e])
		e++;
	while (i <= e)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
