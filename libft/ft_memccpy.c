/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 22:18:10 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/19 18:28:37 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	while (n > 0 && *s != (unsigned char)c)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	if (*s == (unsigned char)c)
	{
		*d = *s;
		d++;
		return (d);
	}
	else
		return (NULL);
}
