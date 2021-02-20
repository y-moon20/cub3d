/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:22:13 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/19 18:23:24 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_size(long long temp)
{
	int			size;

	size = 0;
	if (temp == 0)
		return (1);
	while (temp > 0)
	{
		size++;
		temp /= 10;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	int			size;
	long long	temp;
	char		*ret;

	size = 0;
	temp = n;
	if (temp < 0)
	{
		size++;
		temp *= -1;
	}
	size += num_size(temp);
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret[size--] = '\0';
	if ((temp = n) < 0)
		temp *= -1;
	while ((size + 1 > 0 && n >= 0) || (size > 0 && n < 0))
	{
		ret[size--] = temp % 10 + '0';
		temp /= 10;
	}
	if (n < 0)
		ret[size] = '-';
	return (ret);
}
