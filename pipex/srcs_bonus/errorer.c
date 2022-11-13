/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:48:51 by adian             #+#    #+#             */
/*   Updated: 2022/05/23 19:24:55 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

void	ft_free_split(char **split)
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
		split[k] = NULL;
		k++;
	}
	free(split);
	split = NULL;
}

void	ft_free_arr_split(char ***a_spl)
{
	int	i;

	i = 0;
	while (a_spl[i])
	{
		ft_free_split(a_spl[i]);
		i++;
	}
	free (a_spl);
	a_spl = 0;
}

void	ft_freesher(t_src **s)
{
	if (*s)
	{
		if ((*s)->path)
			ft_free_split((*s)->path);
		if ((*s)->cmd)
			ft_free_arr_split((*s)->cmd);
		free(*s);
		*s = NULL;
	}
}

void	ft_errorer(t_src **s)
{
	perror("Error");
	ft_freesher(&(*s));
	exit(1);
}

int	ft_gnl_sh(char **line)
{
	char	*buffer;
	char	ch;
	int		i;
	int		rb;

	i = 0;
	rb = 0;
	buffer = (char *)malloc(10000 * sizeof(char));
	if (!buffer)
		return (-1);
	rb = read(0, &ch, 1);
	while (rb && ch && ch != '\n')
	{
		if (ch && ch != '\n')
			buffer[i] = ch;
		rb = read(0, &ch, 1);
		i++;
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (rb);
}
