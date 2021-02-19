/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 15:27:42 by yomoon            #+#    #+#             */
/*   Updated: 2020/08/28 01:32:51 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start;
	int		end;
	int		len;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= 0 && ft_strchr(set, s1[end]))
		end--;
	len = end - start + 1;
	if (len <= 0)
		len = 0;
	trim = (char *)malloc(sizeof(char) * (len + 1));
	if (!trim)
		return (0);
	ft_strlcpy(trim, s1 + start, len + 1);
	return (trim);
}
