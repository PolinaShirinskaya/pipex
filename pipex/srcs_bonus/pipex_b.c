/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:28:11 by adian             #+#    #+#             */
/*   Updated: 2022/05/23 19:23:26 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

static void	ft_heredoc(t_src **s, char *stop)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		ft_errorer(s);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (ft_gnl_sh(&line))
		{
			if (0 == ft_strncmp(line, stop, ft_strlen(stop)))
				exit(0);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
}

static void	ft_child_proc(t_src **s, int i, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (-1 == pipe(fd))
		ft_errorer(&(*s));
	pid = fork();
	if (-1 == pid)
		ft_errorer(&(*s));
	if (pid == 0)
	{
		if (i)
			close(fd[0]);
		dup2(fd[1], 1);
		if (-1 == execve((*s)->path[i], (*s)->cmd[i], envp))
			ft_errorer(&(*s));
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, NULL, 0);
	}
}

static void	ft_arg_var(t_src **s, char **argv, char **envp)
{
	int	i;

	i = 0;
	if (0 == ft_strncmp("here_doc", *argv, 8))
		ft_heredoc(s, *(++argv));
	else
		dup2((*s)->file1, 0);
	while (i < (*s)->general - 1)
		ft_child_proc(s, i++, envp);
	dup2((*s)->file2, 1);
	if (-1 == execve((*s)->path[i], (*s)->cmd[i], envp))
		ft_errorer(s);
}

int	main(int argc, char **argv, char **envp)
{
	t_src	*src;

	if (argc < 5)
	{
		perror("Wrong arguments");
		return (1);
	}
	else
	{
		if (!ft_check_arg_b(&src, envp, ++argv, --argc))
			ft_errorer(&src);
		ft_arg_var(&src, argv, envp);
	}
}
