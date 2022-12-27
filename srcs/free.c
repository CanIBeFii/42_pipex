/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:30:59 by fialexan          #+#    #+#             */
/*   Updated: 2022/12/27 11:46:20 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_child(t_pipex *pipex)
{
	int	index;

	index = 0;
	while (pipex->command_1_arguments[index] != NULL)
	{
		free(pipex->command_1_arguments[index]);
		index++;
	}
	index = 0;
	while (pipex->command_2_arguments[index] != NULL)
	{
		free(pipex->command_2_arguments[index]);
		index++;
	}
	index = 0;
	while (pipex->command_paths[index] != NULL)
	{
		free(pipex->command_paths[index]);
		index++;
	}
	free(pipex->command_paths);
	free(pipex->command_1_arguments);
	free(pipex->command_2_arguments);
}

void	free_parent(t_pipex *pipex)
{
	free_child(pipex);
	close(pipex->infile_file_descriptor);
	close(pipex->outfile_file_descriptor);
}
