/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:05:42 by filipe            #+#    #+#             */
/*   Updated: 2022/12/26 18:08:11 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_1(t_pipex pipex, char **envp)
{
	if (dup2(pipex.infile_file_descriptor, STDIN_FILENO) == DUP2_ERROR)
		perror("Dup2 - child1 input");
	if (dup2(pipex.pipe[1], STDOUT_FILENO) == DUP2_ERROR)
		perror("Dup2 - child1 output");
	close(pipex.pipe[0]);
	close(pipex.infile_file_descriptor);
	exit(EXIT_SUCCESS);
}

void	child_2(t_pipex pipex, char **envp)
{
	if (dup2(pipex.pipe[0], STDIN_FILENO) == DUP2_ERROR)
		perror("Dup2 - child1 input");
	if (dup2(pipex.outfile_file_descriptor, STDOUT_FILENO) == DUP2_ERROR)
		perror("Dup2 - child1 output");
	close(pipex.pipe[1]);
	close(pipex.outfile_file_descriptor);
	exit(EXIT_SUCCESS);
}
