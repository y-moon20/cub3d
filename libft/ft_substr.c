/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 17:41:41 by yomoon            #+#    #+#             */
/*   Updated: 2020/08/21 18:32:36 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start < 0 || len < 0)
		return (0);
	if (start > ft_strlen(s))
	{
		ret = ft_calloc(sizeof(char), 1);
		return (ret);
	}
	while (s[start + i] != '\0' && i < len)
		i++;
	ret = ft_calloc(sizeof(char), i + 1);
	if (!ret)
		return (0);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	return (ret);
}
