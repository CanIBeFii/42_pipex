/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:51:02 by fialexan          #+#    #+#             */
/*   Updated: 2022/12/22 17:13:03 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int	format_i(va_list args)
{
	char	*num;
	int		n;

	n = va_arg(args, int);
	num = ft_itoa(n);
	ft_putstr_fd(num, 1);
	n = ft_strlen(num);
	free(num);
	return (n);
}
