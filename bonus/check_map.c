/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:26:45 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/20 16:26:47 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_top(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->map_width)
	{
		if (!(info->map[0][i] == ' ' || info->map[0][i] == '1'))
			print_error(2, "(top)\n", info);
		i++;
	}
}

void	check_map_left(t_info *info, int i, int j)
{
	while (info->map[i][j] == ' ')
		j++;
	if (info->map[i][j] != '1')
		print_error(2, "(left)\n", info);
}

void	check_map_middle(t_info *info, int i, int j)
{
	if (i > 0 && i < info->map_height - 1)
		if (info->map[i - 1][j] == ' ' || info->map[i + 1][j] == ' ')
			if (info->map[i][j] != ' ' && info->map[i][j] != '1')
				print_error(2, "(middle)\n", info);
	if (j > 0 && j < info->map_width)
		if (info->map[i][j - 1] == ' ' || info->map[i][j + 1] == ' ')
			if (info->map[i][j] != ' ' && info->map[i][j] != '1')
				print_error(2, "(middle)\n", info);
}

void	check_map_right(t_info *info, int i, int j)
{
	while (info->map[i][j] == ' ')
		j--;
	if (info->map[i][j] != '1')
		print_error(2, "(right)\n", info);
}

void	check_map_bottom(t_info *info, int i)
{
	int	j;

	j = 0;
	while (j < info->map_width)
	{
		if (!(info->map[i][j] == ' ' || info->map[i][j] == '1'))
			print_error(2, "(bottom)\n", info);
		j++;
	}
}
