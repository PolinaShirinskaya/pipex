/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:43:35 by adian             #+#    #+#             */
/*   Updated: 2022/05/09 13:51:29 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_free_split(char **split)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (split[i])
		i++;
	while (k < i)
	{
		free(split[k]);
		k++;
	}
	free(split);
}

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

static void	ft_add_cmd(char **str, const char *cmd)
{
	char	*tmp;

	tmp = *str;
	*str = ft_strjoin(*str, cmd);
	if (!*str)
		free(tmp);
}

static char	*ft_get_path(char **envp)
{
	char	*path;

	if (!ft_is_valid_path((const char **)(envp)))
		return (NULL);
	while (0 != ft_strncmp(*envp, "PATH", 4))
		envp++;
	path = *envp;
	return (path + 5);
}

char	*ft_get_cmd_env(char **envp, char *cmd)
{
	char	**paths;
	char	**first;
	char	*str;

	paths = ft_split(ft_get_path(envp), ':');
	if (!paths)
		return (NULL);
	first = paths;
	while (*paths)
	{
		str = ft_strjoin(*paths, "/");
		if (!str)
			return (NULL);
		ft_add_cmd(&str, cmd);
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
