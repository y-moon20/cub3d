/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:20:02 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/19 18:40:17 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	if (*str != '\0')
	{
		while (*str != '\0')
			str++;
		if (*str == (char)c)
			return (str);
		str--;
		while (str != (s - 1))
		{
			if (*str == (char)c)
				return (str);
			str--;
		}
		return (NULL);
	}
	else
	{
		if (*str == (char)c)
			return (str);
		return (NULL);
	}
}
