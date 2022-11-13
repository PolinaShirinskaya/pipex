/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:09:30 by adian             #+#    #+#             */
/*   Updated: 2022/05/09 14:00:19 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_child_proc(t_src **s, int *fd, char **envp)
{
	dup2((*s)->file1, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	if (-1 == execve((*s)->path_cmd1, (*s)->cmd1_args, envp))
		ft_errorer(s);
}

static void	ft_parent_proc(t_src **s, int *fd, char **envp)
{
	dup2(fd[0], 0);
	dup2((*s)->file2, 1);
	close(fd[1]);
	if (-1 == execve((*s)->path_cmd2, (*s)->cmd2_args, envp))
		ft_errorer(s);
}

int	main(int argc, char **argv, char **envp)
{
	t_src	*src;
	pid_t	pid;
	int		fd[2];

	if (argc != 5)
	{
		perror("Wrong arguments");
		return (1);
	}
	else
	{
		if (!ft_check_arg(&src, envp, argv))
			ft_errorer(&src);
		if (-1 == pipe(fd))
			ft_errorer(&src);
		pid = fork();
		if (-1 == pid)
			ft_errorer(&src);
		if (0 == pid)
			ft_child_proc(&src, fd, envp);
		waitpid(pid, NULL, 0);
		ft_parent_proc(&src, fd, envp);
	}
	return (0);
}
