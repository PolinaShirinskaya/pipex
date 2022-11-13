/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:31:29 by adian             #+#    #+#             */
/*   Updated: 2021/11/10 14:40:30 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	unsigned char	*s;

	s = (unsigned char *)malloc(number * size);
	if (s != NULL)
	{
		ft_bzero(s, number * size);
		return ((void *)(s));
	}
	return (NULL);
}
