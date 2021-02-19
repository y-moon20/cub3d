/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohchoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 00:57:30 by soohchoi          #+#    #+#             */
/*   Updated: 2020/12/09 01:07:37 by soohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_exit(int n)
{
	exit(0);
	return (n);
}

void	print_error(int n, char *str, t_info *info)
{
	(n == 0) ? ft_putstr_err("Error : Invaild element") : NULL;
	(n == 1) ? ft_putstr_err("Error : Invaild map") : NULL;
	(n == 2) ? ft_putstr_err("Error : Map isn't surrounded by walls") : NULL;
	(str) ? ft_putstr_err(str) : NULL;
	if (info->fd >= 0)
	{
		close(info->fd);
		info->fd = -1;
	}
	exit(1);
}

void	skip_space(char **line)
{
	while (**line == ' ' || **line == '\t' || **line == '\r' ||\
			**line == '\v' || **line == '\f')
		(*line)++;
}

void	free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
