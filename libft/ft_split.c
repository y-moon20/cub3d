/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 11:22:01 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/19 18:32:31 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int		i;
	int		flag;
	int		count;

	count = 0;
	i = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (flag == 1)
			{
				count++;
				flag = 0;
			}
		}
		else
			flag = 1;
		i++;
	}
	if (flag == 1)
		count++;
	return (count);
}

static void	put_word(char *ret[], char const *s, char *str, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (*str != '\0')
	{
		if (*str == c)
		{
			if (len != 0)
			{
				ret[i++] = ft_substr(s, str - s - len, len);
				len = 0;
			}
		}
		else
			len++;
		str++;
	}
	if (len != 0)
		ret[i++] = ft_substr(s, str - s - len, len);
	ret[i] = 0;
}

char		**ft_split(char const *s, char c)
{
	char	**ret;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	ret = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!ret)
		return (NULL);
	put_word(ret, s, str, c);
	return (ret);
}
