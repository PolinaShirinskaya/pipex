/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:27:49 by adian             #+#    #+#             */
/*   Updated: 2021/11/10 14:40:31 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	str1_len;
	size_t	str2_len;
	size_t	cat_len;
	char	*str_cat;

	if (!str1 && !str2)
		return (ft_strdup(""));
	if (str1 && !str2)
		return (ft_strdup(str1));
	if (!str1 && str2)
		return (ft_strdup(str2));
	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	cat_len = str1_len + str2_len + 1;
	str_cat = malloc(sizeof(char) * cat_len);
	if (str_cat != NULL)
	{
		ft_memcpy(str_cat, str1, str1_len);
		ft_memcpy(str_cat + str1_len, str2, str2_len);
		str_cat[cat_len - 1] = '\0';
		return (str_cat);
	}
	return (NULL);
}
