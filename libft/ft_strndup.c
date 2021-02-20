/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 11:29:33 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/19 18:39:20 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(char *str, size_t size)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size && str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
