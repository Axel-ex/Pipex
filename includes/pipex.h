/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:47:59 by achabrer          #+#    #+#             */
/*   Updated: 2023/11/06 10:55:03 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include "../Libft/includes/libft.h"

# define CHILD1 0
# define CHILD2 1
# define STD_USAGE "Usage: <infile> <cmd1> <cmd2> <outfile>"

typedef struct s_pipex
{
	pid_t	pid[2];
	int		fds[2];
	char	**path;
	char	**cmd_arg;
	char	*cmd;
	char	*infile;
	char	*outfile;
	int		fd_in;
	int		fd_out;
}	t_pipex;

//SRC
t_pipex	*init_pipex(char **argv, char **envp);
char	**get_path(char **envp);
void	clean_exit(t_pipex *pipex);
void	exit_error(char *s, t_pipex *pipex);
char	*get_cmd(char *cmd, char **path);

#endif