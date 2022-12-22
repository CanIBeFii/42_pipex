/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:10:59 by fialexan          #+#    #+#             */
/*   Updated: 2022/12/22 17:13:03 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int	format_x_small(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	return (ft_convert_hex((unsigned long)num, 1));
}
