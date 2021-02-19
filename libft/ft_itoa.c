/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 18:17:38 by yomoon            #+#    #+#             */
/*   Updated: 2020/08/23 02:14:56 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_len(long n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
	{
		cnt = 1;
		n *= -1;
	}
	if (n == 0)
		cnt = 1;
	while (n > 0)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt);
}

char	*change_nbr(char *ret, int i, long nbr)
{
	ret[i] = '\0';
	i--;
	if (nbr < 0)
	{
		ret[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
	{
		ret[0] = '0';
		return (ret);
	}
	while (nbr > 0)
	{
		ret[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	return (ret);
}

char	*ft_itoa(int c)
{
	char	*ret;
	long	nbr;
	int		i;

	nbr = c;
	i = count_len(c);
	ret = (char*)malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (0);
	ret = change_nbr(ret, i, nbr);
	return (ret);
}
