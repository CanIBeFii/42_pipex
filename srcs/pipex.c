/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:43:03 by filipe            #+#    #+#             */
/*   Updated: 2022/12/30 15:12:06 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (error_found(ARGC_ERROR));
	pipex.infile_file_descriptor = open(argv[1], O_RDONLY);
	if (pipex.infile_file_descriptor == -1)
		print_error(INFILE_ERROR);
	pipex.outfile_file_descriptor
		= open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.outfile_file_descriptor == -1)
		print_error(OUTFILE_ERROR);
	if (pipe(pipex.pipe) == -1)
		print_error(PIPE);
	pipex_function(pipex, argv, envp);
	return (0);
}

void	pipex_function(t_pipex pipex, char **argv, char **envp)
{
	pipex.command_paths = get_command_paths(envp);
	pipex.command_1_arguments = ft_split(argv[2], ' ');
	pipex.command_2_arguments = ft_split(argv[3], ' ');
	pipex.child_1 = fork();
	if (pipex.child_1 == 0)
		child_1(pipex, envp);
	pipex.child_2 = fork();
	if (pipex.child_2 == 0)
		child_2(pipex, envp);
	close(pipex.pipe[0]);
	close(pipex.pipe[1]);
	waitpid(pipex.child_1, NULL, 0);
	waitpid(pipex.child_2, NULL, 0);
	free_parent(&pipex);
}

char	**get_command_paths(char **envp)
{
	char	**paths;
	int		index;

	index = 0;
	while (envp[index] != NULL)
	{
		if (ft_strncmp(envp[index], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[index] + 5, ':');
			return (paths);
		}
		index++;
	}
	return (NULL);
}
