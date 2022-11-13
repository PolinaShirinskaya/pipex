/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:30:44 by adian             #+#    #+#             */
/*   Updated: 2022/05/08 18:30:56 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_src {
	char	**path;
	char	***cmd;
	int		file1;
	int		file2;
	int		general;
}	t_src;

char	*ft_get_cmd_env(char **envp, char *cmd);
int		ft_check_arg_b(t_src **s, char **envp, char **argv, int argc);

void	ft_freesher(t_src **s);
void	ft_errorer(t_src **s);
void	ft_free_split(char **split);
int		ft_gnl_sh(char **line);
void	ft_free_arr_split(char ***a_spl);

#endif