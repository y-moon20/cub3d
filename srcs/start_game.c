/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohchoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 00:55:02 by soohchoi          #+#    #+#             */
/*   Updated: 2020/12/09 01:08:09 by soohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			info->img.data[info->width * y + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int		main_loop(t_info *info)
{
	raycasting(info);
	sprite_raycasting(info, &info->player);
	draw(info);
	return (1);
}

int		start_game(t_info *info)
{
	info->win =\
			mlx_new_window(info->mlx, info->width, info->height, "cub3D");
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, key_press, info);
	mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, ft_exit, 0);
	mlx_loop_hook(info->mlx, main_loop, info);
	mlx_loop(info->mlx);
	return (1);
}
