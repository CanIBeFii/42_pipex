/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:05:42 by filipe            #+#    #+#             */
/*   Updated: 2022/12/30 15:19:19 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_command(char **paths, char *command_name)
{
	int		index;
	char	*temporary;
	char	*command;

	index = 0;
	while (paths[index] != NULL)
	{
		temporary = ft_strjoin(paths[index], "/");
		command = ft_strjoin(temporary, command_name);
		free(temporary);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		index++;
	}
	return (NULL);
}

void	child_1(t_pipex pipex, char **envp)
{
	char	*command;

	if (dup2(pipex.infile_file_descriptor, STDIN_FILENO) == DUP2_ERROR)
		perror("Dup2 - child1 input");
	if (dup2(pipex.pipe[1], STDOUT_FILENO) == DUP2_ERROR)
		perror("Dup2 - child1 output");
	close(pipex.pipe[0]);
	close(pipex.infile_file_descriptor);
	command = get_command(pipex.command_paths,
			pipex.command_1_arguments[0]);
	if (command == NULL)
	{
		free_child(&pipex);
		error_found(COMMAND_ERROR);
		exit(EXIT_FAILURE);
	}
	execve(command, pipex.command_1_arguments, envp);
	free_child(&pipex);
	free(command);
	exit(EXIT_SUCCESS);
}

void	child_2(t_pipex pipex, char **envp)
{
	char	*command;

	if (dup2(pipex.pipe[0], STDIN_FILENO) == DUP2_ERROR)
		perror("Dup2 - child1 input");
	if (dup2(pipex.outfile_file_descriptor, STDOUT_FILENO) == DUP2_ERROR)
		perror("Dup2 - child1 output");
	close(pipex.pipe[1]);
	close(pipex.outfile_file_descriptor);
	command = get_command(pipex.command_paths,
			pipex.command_2_arguments[0]);
	if (command == NULL)
	{
		free_child(&pipex);
		error_found(COMMAND_ERROR);
		exit(EXIT_FAILURE);
	}
	execve(command, pipex.command_2_arguments, envp);
	free_child(&pipex);
	free(command);
	exit(EXIT_SUCCESS);
}
