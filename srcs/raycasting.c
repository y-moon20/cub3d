/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohchoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 00:55:58 by soohchoi          #+#    #+#             */
/*   Updated: 2020/12/09 01:22:41 by soohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_info *info)
{
	int	x;

	x = 0;
	cast_floor_ceiling(info);
	while (x < info->width)
	{
		init_ray(info, &info->player, &info->ray, x);
		calculate_step_direction(&info->player, &info->ray);
		perform_dda(info, &info->ray);
		calculate_wall_distance(&info->player, &info->ray);
		calculate_wall_height(info, &info->ray);
		get_wall_tex(&info->player, &info->ray);
		get_wall_color(info, &info->ray, x);
		info->z_buffer[x] = info->ray.perp_wall_dist;
		x++;
	}
}

void	cast_floor_ceiling(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (y > info->height / 2)
				info->buf[y][x] = info->floor;
			else
				info->buf[y][x] = info->ceil;
			x++;
		}
		y++;
	}
}

void	init_ray(t_info *info, t_player *player, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)info->width - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
	ray->hit = 0;
}

void	calculate_step_direction(t_player *player, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->y) * ray->delta_dist_y;
	}
}

void	perform_dda(t_info *info, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = (ray->step_x == -1) ? 0 : 1;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = (ray->step_y == -1) ? 2 : 3;
		}
		if (info->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}
