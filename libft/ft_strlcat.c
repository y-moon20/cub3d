/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 13:23:59 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/19 18:36:53 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	d_size;
	size_t	s_size;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	d_size = i;
	while (src[j] != '\0')
		j++;
	s_size = j;
	if (dstsize <= d_size)
		return (dstsize + s_size);
	i = 0;
	while (i < dstsize - d_size - 1 && src[i] != '\0')
	{
		dst[i + d_size] = src[i];
		i++;
	}
	dst[i + d_size] = '\0';
	return (d_size + s_size);
}
