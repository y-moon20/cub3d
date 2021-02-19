/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohchoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 00:54:50 by soohchoi          #+#    #+#             */
/*   Updated: 2020/12/09 01:16:57 by soohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_pos_spr(t_info *info, int i, int x, int y)
{
	info->spr[i].x = 0.5f + x;
	info->spr[i].y = 0.5f + y;
}

void	set_sprite(t_info *info)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	if (info->num_sprite > 0)
	{
		if (!(info->spr = (t_spr *)malloc(sizeof(t_spr) * info->num_sprite)))
			print_error(-1, "Error : Malloc error\n", info);
		while (y < info->map_height)
		{
			x = 0;
			while (x < info->map_width)
			{
				if (info->map[y][x] == '2')
				{
					set_pos_spr(info, i, x, y);
					i++;
				}
				x++;
			}
			y++;
		}
	}
}

void	set_dir(t_info *info)
{
	int	rot;

	rot = 0;
	if (info->dir == 'N')
		rot = 270;
	else if (info->dir == 'S')
		rot = 90;
	else if (info->dir == 'E')
		rot = 0;
	else if (info->dir == 'W')
		rot = 180;
	rotate_player(&info->player, rot * (M_PI / 180));
}
