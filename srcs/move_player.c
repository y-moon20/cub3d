/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohchoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 00:55:28 by soohchoi          #+#    #+#             */
/*   Updated: 2020/12/09 01:21:43 by soohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_info *info, t_player *player, double move_speed)
{
	char	x;
	char	y;

	x = info->map[(int)player->y][(int)(player->x +\
			player->dir_x * move_speed)];
	y = info->map[(int)(player->y + player->dir_y *\
			move_speed)][(int)player->x];
	if (x != '1' && x != '2')
		player->x += player->dir_x * move_speed;
	if (y != '1' && y != '2')
		player->y += player->dir_y * move_speed;
}

void	move_player_left_right(t_info *info,\
								t_player *player, double move_speed)
{
	char	x;
	char	y;

	x = info->map[(int)player->y][(int)(player->x +\
			player->dir_y * move_speed)];
	y = info->map[(int)(player->y + -player->dir_x *\
			move_speed)][(int)player->x];
	if (x != '1' && x != '2')
		player->x += player->dir_y * move_speed;
	if (y != '1' && y != '2')
		player->y += -player->dir_x * move_speed;
}

int		key_press(int key, t_info *info)
{
	if (key == K_W || key == K_AR_U)
		move_player(info, &info->player, info->player.move_speed);
	if (key == K_S || key == K_AR_D)
		move_player(info, &info->player, -info->player.move_speed);
	if (key == K_A)
		move_player_left_right(info, &info->player, -info->player.move_speed);
	if (key == K_D)
		move_player_left_right(info, &info->player, info->player.move_speed);
	if (key == K_AR_L)
		rotate_player(&info->player, info->player.rot_speed);
	if (key == K_AR_R)
		rotate_player(&info->player, -info->player.rot_speed);
	if (key == K_ESC)
		exit(0);
	return (0);
}

void	rotate_player(t_player *player, double rot_angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_angle) -\
					player->dir_y * sin(rot_angle);
	player->dir_y = old_dir_x * sin(rot_angle) +\
					player->dir_y * cos(rot_angle);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_angle) -\
					player->plane_y * sin(rot_angle);
	player->plane_y = old_plane_x * sin(rot_angle) +\
					player->plane_y * cos(rot_angle);
}
