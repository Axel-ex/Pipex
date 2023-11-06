/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:03:12 by achabrer          #+#    #+#             */
/*   Updated: 2023/11/03 14:01:58 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (execve(argv[1], &argv[1], NULL))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
