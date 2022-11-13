/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:37:37 by adian             #+#    #+#             */
/*   Updated: 2021/11/10 14:40:30 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i++] = str[j];
		str[j--] = tmp;
	}
	return (str);
}

static size_t	ft_intlen(int nb)
{
	size_t	count;

	count = 1;
	while (nb / 10)
	{
		++count;
		nb /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long		nb;
	size_t		nlen;
	size_t		i;
	char		*nb_str;

	nb = n;
	i = 0;
	if (n < 0)
		nb = nb * -1;
	nlen = ft_intlen(n);
	nb_str = ft_calloc(nlen + 1 + (n < 0), sizeof(char));
	if (!nb_str)
		return (NULL);
	ft_memset(nb_str, '0', nlen + (n < 0));
	while (nb)
	{
		nb_str[i++] = nb % 10 + 48;
		nb /= 10;
	}
	if (n < 0)
		nb_str[i] = '-';
	return (ft_strrev(nb_str));
}
