/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:12:22 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/20 16:31:54 by yomoon           ###   ########.fr       */
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
