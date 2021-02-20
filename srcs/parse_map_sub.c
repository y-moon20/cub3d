/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:28:35 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/20 16:28:37 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	count_arg(t_info *info, int i, int j, int *dir_count)
{
	if (is_dir(info->map[i][j]) == 1)
	{
		info->dir = info->map[i][j];
		info->player.x = 0.5f + j;
		info->player.y = 0.5f + i;
		(*dir_count)++;
	}
	if (info->map[i][j] == '2')
		info->num_sprite++;
}

int		is_dir(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return (1);
	return (0);
}

int		is_map_arg(char c)
{
	if (is_dir(c) || c == ' ' || (c >= '0' && c <= '2'))
		return (1);
	return (0);
}
