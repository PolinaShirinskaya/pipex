/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:02:10 by adian             #+#    #+#             */
/*   Updated: 2022/04/30 20:17:36 by adian            ###   ########.fr       */
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

static void	ft_freesher(t_src **s)
{
	if (*s)
	{
		if ((*s)->path_cmd1)
			free((*s)->path_cmd1);
		if ((*s)->path_cmd2)
			free((*s)->path_cmd2);
		if ((*s)->cmd1_args)
			ft_free_split((*s)->cmd1_args);
		if ((*s)->cmd2_args)
			ft_free_split((*s)->cmd2_args);
		if ((*s)->file1 != 0)
			close((*s)->file1);
		if ((*s)->file2 != 0)
			close((*s)->file2);
		if (*s)
			free(*s);
	}
}

void	ft_errorer(t_src **s)
{
	perror("Error");
	ft_freesher(&(*s));
	exit(1);
}
