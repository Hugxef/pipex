/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:27:31 by hugrene           #+#    #+#             */
/*   Updated: 2022/07/04 13:27:32 by hugrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	usage(void)
{
	write(2, "usage: ./pipex [file1] [cmd1] [cmd2] [file2]\n", 45);
	exit(EXIT_FAILURE);
}

void	terminate(char *m)
{
	if (errno == 0)
		write(2, "Error\n", 6);
	else
		perror(m);
	exit(EXIT_FAILURE);
}

void	cmd_not_found(char **cmd)
{
	write(2, cmd[0], ft_strlen(cmd[0]));
	write(2, ": command not found\n", 20);
	free_split(cmd);
	exit(EXIT_FAILURE);
}

void	free_split(char **args)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (args[size])
		size++;
	while (i < size)
		free(args[i++]);
	free(args);
}
