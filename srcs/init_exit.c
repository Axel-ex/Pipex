/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:04:44 by achabrer          #+#    #+#             */
/*   Updated: 2023/11/06 10:25:09 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_pipex	*init_pipex(char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	pipex->path = get_path(envp);
	pipex->infile = argv[1];
	pipex->outfile = argv[4];
	pipex->cmd = NULL;
	pipex->cmd_arg = NULL;
	pipex->fd_in = open(pipex->infile, O_RDONLY);
	pipex->fd_out = open(pipex->outfile, O_WRONLY | O_CREAT, 0777);
	if (pipex->fd_in == -1 || pipex->fd_out == -1)
		exit_error(strerror(errno), pipex);
	return (pipex);
}

static void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	clean_exit(t_pipex *pipex)
{
	if (pipex->cmd_arg)
		free_matrix(pipex->cmd_arg);
	if (pipex->cmd)
		free(pipex->cmd);
	free_matrix(pipex->path);
	close(pipex->fd_in);
	close(pipex->fd_out);
	free(pipex);
}

void	exit_error(char *s, t_pipex *pipex)
{
	perror(s);
	clean_exit(pipex);
	exit (EXIT_FAILURE);
}
