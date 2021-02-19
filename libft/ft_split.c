/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 11:30:41 by yomoon            #+#    #+#             */
/*   Updated: 2020/09/29 22:36:59 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		strlen_sep(char const *str, char c)
{
	int		ret;

	ret = 0;
	while (*str != '\0')
	{
		if (*str == c)
			break ;
		++ret;
		++str;
	}
	return (ret);
}

static int		count_word(char const *str, char c)
{
	int		ret;
	int		len;

	ret = 0;
	while (*str != '\0')
	{
		len = strlen_sep(str, c);
		if (len != 0)
		{
			++ret;
			str += len;
		}
		else
			++str;
	}
	return (ret);
}

static void		ft_free(char **ret)
{
	int	i;

	i = 0;
	if (*ret[0] != '\0')
	{
		while (*ret[i] != '\0')
			free(ret[i++]);
	}
	free(ret);
}

static int		split_alloc(char **ret, int len, int i)
{
	if (!(ret[i] = (char*)malloc(sizeof(char) * (len + 1))))
	{
		ft_free(ret);
		return (0);
	}
	return (1);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	int		len;
	int		i;

	if (!s)
		return (0);
	len = count_word(s, c);
	if (!(ret = (char**)malloc(sizeof(char*) * (len + 1))))
		return (0);
	ret[len] = 0;
	i = 0;
	while (*s != '\0')
	{
		len = strlen_sep(s, c);
		if (len != 0)
		{
			if (!(split_alloc(ret, len, i)))
				return (0);
			ft_strlcpy(ret[i++], s, len + 1);
			s += len;
		}
		else
			s++;
	}
	return (ret);
}
