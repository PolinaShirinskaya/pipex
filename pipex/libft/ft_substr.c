/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:25:30 by adian             #+#    #+#             */
/*   Updated: 2022/04/30 20:13:06 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	unsigned char	*substr;

	if (!str)
		return (NULL);
	if ((start + len) >= ft_strlen(str))
		len = ft_strlen(str) - start;
	if ((start) > ft_strlen(str))
		return (ft_strdup(""));
	substr = (unsigned char *)malloc((len + 1) * sizeof(char));
	if (substr != NULL)
	{
		ft_memcpy(substr, str + start, len);
		substr[len] = 0;
		return ((char *)(substr));
	}
	return (NULL);
}
