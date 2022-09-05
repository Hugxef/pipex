/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:27:04 by hugrene           #+#    #+#             */
/*   Updated: 2022/07/04 13:27:05 by hugrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(int *pipefd, int *fd, char **av, char **envp)
{
	char	**cmd;
	pid_t	c_pid;

	c_pid = fork();
	if (c_pid < 0)
		terminate("fork");
	if (c_pid == 0)
	{
		fd[0] = open(av[1], O_RDONLY);
		if (fd[0] < 0)
			terminate(av[1]);
		cmd = ft_split(av[2], ' ');
		close(pipefd[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		if (cmd[0] && path(cmd[0], envp))
		{
			execve(path(cmd[0], envp), cmd, envp);
			free_split(cmd);
		}
		else
			cmd_not_found(cmd);
	}
}

void	child_two(int *pipefd, int *fd, char **av, char **envp)
{
	char	**cmd;
	pid_t	c_pid;

	c_pid = fork();
	if (c_pid < 0)
		terminate("fork");
	if (c_pid == 0)
	{
		fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] < 0)
			terminate(av[4]);
		cmd = ft_split(av[3], ' ');
		close(pipefd[1]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		if (cmd[0] && path(cmd[0], envp))
		{
			execve(path(cmd[0], envp), cmd, envp);
			free_split(cmd);
		}
		else
			cmd_not_found(cmd);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	pipefd[2];
	int	fd[2];
	int	status;

	errno = 0;
	if (ac != 5)
		usage();
	if (pipe(pipefd) < 0)
		terminate(NULL);
	child_one(pipefd, fd, av, envp);
	child_two(pipefd, fd, av, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
	return (0);
}
