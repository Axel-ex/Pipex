/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:49:51 by achabrer          #+#    #+#             */
/*   Updated: 2023/11/03 10:53:25 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(void)
{
	int		fds[2];
	char	buf;
	pid_t	child_id;

	if (pipe(fds) == -1)
	{
		perror("pipe");
		return (EXIT_FAILURE);
	}
	child_id = fork();
	if (child_id == -1)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	if (child_id == 0)
	{
		close(fds[1]);
		printf("child: I am listening to a secret\n");
		printf("child: ");
		while (read(fds[0], &buf, 1) > 0)
			printf("%c", buf);
		printf("\n");
		printf("child: my pid is %d\n", getpid());
		printf("child: my fork is %d\n", child_id);
		close(fds[0]);
		return (EXIT_SUCCESS);
	}
	else
	{
		close(fds[0]);
		ft_putstr_fd("this is my secret\n", fds[1]);
		close(fds[1]);
		printf("parent: my pid is %d\n", getpid());
		printf("parent: my fork is %d\n", child_id);
		return (EXIT_SUCCESS);
	}
}
