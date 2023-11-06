/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:02:06 by achabrer          #+#    #+#             */
/*   Updated: 2023/11/06 11:20:24 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	run_child(t_pipex *pipex, char **argv)
{
	pipex->cmd_arg = ft_split(argv[2], ' ');
	pipex->cmd = get_cmd(pipex->cmd_arg[0], pipex->path);
	close(pipex->fds[0]);
	dup2(pipex->fd_in, STDIN_FILENO);
	dup2(pipex->fds[1], STDOUT_FILENO);
	if (execve(pipex->cmd, pipex->cmd_arg, pipex->path) == -1)
		exit_error("first child execve", pipex);
}

void	run_second_child(t_pipex *pipex, char **argv)
{
	wait(NULL);
	pipex->cmd_arg = ft_split(argv[3], ' ');
	pipex->cmd = get_cmd(pipex->cmd_arg[0], pipex->path);
	close(pipex->fds[1]);
	dup2(pipex->fds[0], STDIN_FILENO);
	dup2(pipex->fd_out, STDOUT_FILENO);
	if (execve(pipex->cmd, pipex->cmd_arg, pipex->path) == -1)
		exit_error("second child execve", pipex);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc != 5)
	{
		ft_printf("%s\n", STD_USAGE);
		exit(EXIT_FAILURE);
	}
	pipex = init_pipex(argv, envp);
	pipe(pipex->fds);
	pipex->pid[CHILD1] = fork();
	if (pipex->pid[CHILD1] == -1)
		exit_error("first child pid", pipex);
	if (!pipex->pid[CHILD1])
		run_child(pipex, argv);
	pipex->pid[CHILD2] = fork();
	if (pipex->pid[CHILD2] == -1)
		exit_error("second child pid", pipex);
	if (!pipex->pid[CHILD2])
		run_second_child(pipex, argv);
	wait(NULL);
	clean_exit(pipex);
	exit (EXIT_SUCCESS);
}
