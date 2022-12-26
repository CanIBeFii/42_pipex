/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:04:05 by fialexan          #+#    #+#             */
/*   Updated: 2022/12/26 17:10:26 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_found(char *error)
{
	ft_putendl_fd(error, 2);
	return (1);
}

void	print_error(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}
