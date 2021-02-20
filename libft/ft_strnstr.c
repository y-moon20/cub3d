/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:29:13 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/19 18:39:51 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*s1;
	char	*s2;
	int		s2_len;

	s1 = (char *)haystack;
	s2 = (char *)needle;
	s2_len = 0;
	while (s2[s2_len] != '\0')
		s2_len++;
	if (s2_len == 0)
		return (s1);
	while (*s1 != '\0' && (int)(len - s2_len) >= 0)
	{
		if (ft_strncmp(s1, s2, s2_len) == 0)
			return (s1);
		s1++;
		len--;
	}
	return (NULL);
}
