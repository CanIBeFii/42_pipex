/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:43:03 by filipe            #+#    #+#             */
/*   Updated: 2022/12/22 19:53:39 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// linha 23 handle erro maybe
int	main(int argc, char **argv)
{
	int		input_fd;
	int		output_fd;
	char	**command_1;
	char	**command_2;
	
	input_fd = open(argv[1], O_RDONLY);
	output_fd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (input_fd < 0 || output_fd < 0)
		return (-1);
	command_1 = ft_split(argv[2], ' ');
	if (command_1 == NULL)
		return (-1);
	command_2 = ft_split(argv[3], ' ');
	if (command_2 == NULL)
		return (-1);
	
	return (0);
}

void	pipex(int input_fd, int output_fd, char **command_1, char **command_2)
{
	int		pipex_pipe[2];
	int		pipe_status;
	int		child_status;
	pid_t	child1;
	pid_t	child2;
	
	pipe_status = pipe(pipex_pipe);
	if (pipe_status == PIPE_ERROR)
		return ;
	child1 = fork();
	if (child1 < 0)
		return (perror("Child1"));
	if (child1 == 0)
		child_1_fork(input_fd, pipex_pipe);
	child2 = fork();
	if (child2 < 0)
		return (perror("Child2"));
	if (child2 == 0)
		child_2_fork(output_fd, pipex_pipe);
	close(pipex_pipe[0]);
	close(pipex_pipe[1]);
	waitpid(child1, &child_status, 0);
	waitpid(child2, &child_status, 0);
}
