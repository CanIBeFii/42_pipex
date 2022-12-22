/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:34:42 by filipe            #+#    #+#             */
/*   Updated: 2022/12/22 19:53:57 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H 

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>

// Defines

# define PIPE_ERROR -1
# define DUP2_ERROR -1

// Pipex

void	pipex(int input_fd, int output_fd, char **command_1, char **command_2);

// Child Forks

void	child_1_fork(int input_fd, int *pipe);

void	child_2_fork(int output_fd, int *pipe);

#endif