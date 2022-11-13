/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:24:06 by adian             #+#    #+#             */
/*   Updated: 2021/11/10 14:40:30 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)(src);
	while (n)
	{
		if (*str == (unsigned char)(c))
		{
			src = str;
			return ((char *)(src));
		}
		str++;
		n--;
	}
	return (NULL);
}
