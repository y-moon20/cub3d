/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 00:08:15 by yomoon            #+#    #+#             */
/*   Updated: 2020/12/30 03:08:34 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t size)
{
	char	*dup;
	size_t	i;

	if (!s1 || size < 0)
		return (0);
	dup = (char*)malloc(sizeof(char) * size + 1);
	if (!dup)
		return (0);
	i = 0;
	while (i < size && s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
