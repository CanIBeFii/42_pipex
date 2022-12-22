/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:05:42 by filipe            #+#    #+#             */
/*   Updated: 2022/12/22 19:28:32 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_1_fork(int input_fd, int *pipe)
{
	if (dup2(input_fd, STDIN_FILENO) == DUP2_ERROR)
		perror("Dup2 - child1 input");
	if (dup2(pipe[1], STDOUT_FILENO) == DUP2_ERROR)
		perror("Dup2 - child1 output");
	close(pipe[0]);
	close(input_fd);
	
}

void	child_2_fork(int output_fd, int *pipe)
{
	if (dup2(pipe[0], STDIN_FILENO) == DUP2_ERROR)
		perror("Dup2 - child1 input");
	if (dup2(output_fd, STDOUT_FILENO) == DUP2_ERROR)
		perror("Dup2 - child1 output");
	close(pipe[1]);
	close(output_fd);
}
