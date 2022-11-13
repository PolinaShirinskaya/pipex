/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:44:21 by adian             #+#    #+#             */
/*   Updated: 2022/05/08 18:42:04 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

static int	ft_is_valid_path(const char **envp)
{
	if (*envp == 0)
		return (0);
	while (0 != ft_strncmp(*envp, "PATH", 4))
		envp++;
	if (*envp == 0)
		return (0);
	return (1);
}

static char	*ft_get_paths(char **envp)
{
	char	*ptr;

	if (!ft_is_valid_path((const char **)(envp)))
		return (NULL);
	while (0 != ft_strncmp(*envp, "PATH", 4))
		envp++;
	ptr = *envp;
	return (ptr + 5);
}

static void	ft_add_cmd(char **str1, const char *str2, int trig)
{
	char	*tmp;

	tmp = *str1;
	*str1 = ft_strjoin(*str1, str2);
	if (!*str1)
		free(tmp);
	else if (trig)
		free(tmp);
}

char	*ft_get_cmd_env(char **envp, char *cmd)
{
	char	**paths;
	char	*str;
	char	**first;

	paths = ft_split(ft_get_paths(envp), ':');
	if (!paths)
		return (NULL);
	first = paths;
	while (*paths)
	{
		str = ft_strjoin(*paths, "/");
		if (!str)
			return (NULL);
		ft_add_cmd(&str, cmd, 1);
		if (0 == access(str, F_OK))
		{
			ft_free_split(first);
			return (str);
		}
		free(str);
		paths++;
	}
	ft_free_split(first);
	return (NULL);
}
