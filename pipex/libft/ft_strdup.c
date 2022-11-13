/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:38:15 by adian             #+#    #+#             */
/*   Updated: 2021/11/10 14:40:31 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	unsigned char	*s;
	int				str_len;

	str_len = ft_strlen(str) + 1;
	s = (unsigned char *)malloc(str_len * sizeof(str[0]));
	if (s != NULL)
	{
		ft_memcpy(s, str, str_len++);
		return ((char *)(s));
	}
	return (NULL);
}
