/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 12:24:16 by yomoon            #+#    #+#             */
/*   Updated: 2020/08/14 00:44:19 by yj               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*string;
	size_t	i;

	string = (char *)s;
	i = 0;
	while (i < n)
	{
		string[i] = 0;
		i++;
	}
}
