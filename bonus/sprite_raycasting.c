/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_raycasting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:29:12 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/20 16:30:02 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_raycasting(t_info *info, t_player *player)
{
	int	i;
	int	stripe;

	sort_sprite(info, player);
	i = 0;
	while (i < info->num_sprite)
	{
		translate_sprite(info, player, &info->s_ray, i);
		calculate_sprite_height(info, &info->s_ray);
		calculate_sprite_width(info, &info->s_ray);
		stripe = info->s_ray.draw_start_x;
		while (stripe < info->s_ray.draw_end_x)
		{
			get_sprite_color(info, &info->s_ray, stripe);
			stripe++;
		}
		i++;
	}
}

void	sort(t_info *info)
{
	int		i;
	int		j;
	int		max;
	t_spr	temp;

	i = -1;
	while (++i < info->num_sprite - 1)
	{
		max = i;
		j = i;
		while (++j < info->num_sprite)
			if (info->spr[j].dist > info->spr[max].dist)
				max = j;
		if (i != max)
		{
			temp = info->spr[i];
			info->spr[i] = info->spr[max];
			info->spr[max] = temp;
		}
	}
}

void	sort_sprite(t_info *info, t_player *player)
{
	int	i;

	i = 0;
	while (i < info->num_sprite)
	{
		info->spr[i].dist = ((player->x - info->spr[i].x) * (player->x -\
		info->spr[i].x) + (player->y - info->spr[i].y) * (player->y -\
		info->spr[i].y));
		i++;
	}
	sort(info);
}
