/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 23:29:51 by yomoon            #+#    #+#             */
/*   Updated: 2020/09/29 22:28:58 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dup;

	dup = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!dup || !s1)
		return (0);
	ft_strlcpy(dup, s1, ft_strlen(s1) + 1);
	return (dup);
}
