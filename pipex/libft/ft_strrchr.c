/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:53:26 by adian             #+#    #+#             */
/*   Updated: 2021/11/10 14:40:32 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long long	i;
	char		*sy;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)(c))
		{
			sy = (char *)(s + i);
			return (sy);
		}
		i--;
	}
	return (0);
}
