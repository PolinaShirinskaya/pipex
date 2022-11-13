/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:58:51 by adian             #+#    #+#             */
/*   Updated: 2022/04/30 20:06:08 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_src {
	char	**cmd1_args;
	char	**cmd2_args;
	char	*path_cmd1;
	char	*path_cmd2;
	int		file1;
	int		file2;
}	t_src;

char	*ft_get_cmd_env(char **envp, char *command);
int		ft_check_arg(t_src **s, char **envp, char **argv);
void	ft_errorer(t_src **s);

#endif