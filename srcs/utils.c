/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:09:42 by achabrer          #+#    #+#             */
/*   Updated: 2023/11/05 17:35:37 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_path(char **envp)
{
	int		i;
	char	*path_var;
	char	**res;

	i = 0;
	while (envp[i] != NULL)
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
			break ;
		i++;
	}
	path_var = envp[i];
	i = 0;
	while (i < 5)
	{
		path_var++;
		i++;
	}
	res = ft_split(path_var, ':');
	return (res);
}

char	*get_cmd(char *cmd, char **path)
{
	int		i;
	char	*cmd_path;

	i = 0;
	while (path[i])
	{
		cmd_path = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(cmd_path, cmd);
		if (!access(cmd_path, R_OK | F_OK))
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}
