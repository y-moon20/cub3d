/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:20:47 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/19 18:20:58 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = (char *)malloc(size * count);
	if (!ret)
		return (NULL);
	ft_memset(ret, 0, size * count);
	return ((void *)ret);
}
