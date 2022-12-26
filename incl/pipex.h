/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:34:42 by filipe            #+#    #+#             */
/*   Updated: 2022/12/26 18:29:04 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H 

# include "../libft/incl/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>

// Defines

# define PIPE_ERROR -1
# define DUP2_ERROR -1
# define ARGC_ERROR "Wrong number of arguments"
# define INFILE_ERROR "Infile"
# define OUTFILE_ERROR "Output"
# define PIPE "Pipe"

// Type

typedef struct s_pipex
{
	pid_t	child_1;
	pid_t	child_2;
	int		pipe[2];
	int		infile_file_descriptor;
	int		outfile_file_descriptor;
	char	**command_paths;
	char	**command_1_arguments;
	char	**command_2_arguments;
}	t_pipex;

// Pipex

void	pipex_function(t_pipex pipex, char **argv, char **envp);

char	**get_command_paths(char **envp);

// Child Forks

void	child_1(t_pipex pipex, char **envp);

void	child_2(t_pipex pipex, char **envp);

// Error Management

int		error_found(char *error);

void	print_error(char *error);

#endif