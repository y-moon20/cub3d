/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:17:20 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/20 16:28:03 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_element(t_info *info)
{
	info->width = 0;
	info->height = 0;
	info->n_tex_path = NULL;
	info->s_tex_path = NULL;
	info->w_tex_path = NULL;
	info->e_tex_path = NULL;
	info->p_tex_path = NULL;
	info->floor = -1;
	info->ceil = -1;
	info->map_width = 0;
	info->map_height = 0;
	info->num_sprite = 0;
	info->spr = NULL;
	info->map = NULL;
	info->buf = NULL;
	info->z_buffer = NULL;
}

void	is_valid_map(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	check_map_top(info);
	while (i < info->map_height - 1)
	{
		j = 0;
		check_map_left(info, i, j);
		while (j < info->map_width)
		{
			check_map_middle(info, i, j);
			j++;
		}
		check_map_right(info, i, j - 1);
		i++;
	}
	check_map_bottom(info, i);
}

void	check_info(t_info *info)
{
	if (!info->width || !info->height || !info->n_tex_path ||\
		!info->s_tex_path || !info->w_tex_path || !info->e_tex_path ||\
		!info->p_tex_path || info->floor == -1 || info->ceil == -1 ||\
		!info->map_width || !info->map_height)
		print_error(-1, "Error : Missing element\n", info);
}

void	init_buffer(t_info *info)
{
	int	i;

	i = 0;
	if (!(info->buf = ft_calloc(info->height, sizeof(int **))))
		print_error(-1, "Error : Malloc failed\n", info);
	while (i < info->height)
	{
		if (!(info->buf[i] = ft_calloc(info->width, sizeof(int *))))
			print_error(-1, "Error : Malloc failed\n", info);
		i++;
	}
	if (!(info->z_buffer = ft_calloc(info->width, sizeof(double *))))
		print_error(-1, "Error : Malloc failed\n", info);
}

void	start_parse(t_info *info, char *cub)
{
	init_element(info);
	if ((info->fd = open(cub, O_RDONLY)) <= -1)
		ft_putstr_err("Error : Couldn't open file.\n");
	parse_cub(info);
	is_valid_map(info);
	check_info(info);
	set_sprite(info);
	set_dir(info);
	init_buffer(info);
	init_texture(info);
	info->mlx = mlx_init();
	load_texture(info);
	info->img.img = mlx_new_image(info->mlx, info->width, info->height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img,\
			&info->img.bpp, &info->img.size_l, &info->img.endian);
}
