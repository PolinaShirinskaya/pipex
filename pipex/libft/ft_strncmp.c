/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:16:30 by adian             #+#    #+#             */
/*   Updated: 2021/11/10 14:40:32 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t num)
{
	size_t	i;

	i = 0;
	if (num == 0)
		return (0);
	while (string1[i] != '\0' && string1[i] == string2[i] && i < num - 1)
		i++;
	return ((unsigned char)(string1[i]) - (unsigned char)(string2[i]));
}
