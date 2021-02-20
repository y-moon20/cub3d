/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 22:12:22 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/20 16:27:21 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player *player)
{
	player->dir_x = -1.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.66;
	player->move_speed = 0.05;
	player->rot_speed = 0.05;
}

int		init_game(char *cub, int bmp)
{
	t_info	info;

	init_player(&info.player);
	start_parse(&info, cub);
	if (bmp == 1)
		return (print_bmp(&info));
	return (start_game(&info));
}

int		check_name(char *file, char *str)
{
	int	i;

	i = ft_strlen(file);
	if (i > 4 && !ft_strncmp(&file[i - 4], str, 4))
		return (1);
	return (0);
}

int		main(int ac, char *av[])
{
	if (ac == 3 && check_name(av[1], ".cub") && !ft_strncmp(av[2], "--save", 6))
		return (init_game(av[1], 1));
	else if (ac == 2 && check_name(av[1], ".cub"))
		return (init_game(av[1], 0));
	else
		ft_putstr_err("Error : Invalid arguments\n");
	return (0);
}
