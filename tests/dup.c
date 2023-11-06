/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:17:30 by achabrer          #+#    #+#             */
/*   Updated: 2023/11/05 11:47:36 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd;
	int	i;

	fd = open("test.txt", O_WRONLY | O_CREAT);
	if (fd == -1)
	{
		perror("open");
		return (errno);
	}
	i = 0;
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	dup2(fd, STDOUT_FILENO);
	printf("test from program");
	return (EXIT_SUCCESS);
}
