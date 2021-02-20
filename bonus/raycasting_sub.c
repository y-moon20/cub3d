/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:29:08 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/20 16:29:09 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_wall_distance(t_player *player, t_ray *ray)
{
	if (ray->side <= 1)
		ray->perp_wall_dist = (ray->map_x - player->x +\
				(1 - ray->step_x) / 2) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - player->y +\
				(1 - ray->step_y) / 2) / ray->dir_y;
}

void	calculate_wall_height(t_info *info, t_ray *ray)
{
	ray->line_height = (int)(info->height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + info->height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + info->height / 2;
	if (ray->draw_end >= info->height)
		ray->draw_end = info->height - 1;
}

void	get_wall_tex(t_player *player, t_ray *ray)
{
	if (ray->side <= 1)
		ray->wall_x = player->y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = player->x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)TEX_WIDTH);
	if ((ray->side == 0 || ray->side == 1) && ray->dir_x > 0)
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->dir_y < 0)
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
}

void	get_wall_color(t_info *info, t_ray *ray, int x)
{
	int	color;
	int	y;

	ray->step = 1.0 * TEX_HEIGHT / ray->line_height;
	ray->tex_pos = (ray->draw_start - info->height / 2 +\
			ray->line_height / 2) * ray->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (TEX_HEIGHT - 1);
		ray->tex_pos += ray->step;
		color = info->tex[ray->side][TEX_HEIGHT * ray->tex_y + ray->tex_x];
		if (ray->side >= 2)
			color = (color >> 1) & 8355711;
		info->buf[y][x] = color;
		y++;
	}
}
