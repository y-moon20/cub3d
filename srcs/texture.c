/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:11:51 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/20 16:31:26 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_info *info)
{
	int	i;
	int	j;

	if (!(info->tex = (int **)malloc(sizeof(int *) * 5)))
		print_error(-1, "Error : Malloc failed\n", info);
	i = 0;
	while (i < 5)
	{
		if (!(info->tex[i] = (int *)malloc(sizeof(int) *\
						(TEX_HEIGHT * TEX_WIDTH))))
			print_error(-1, "Error : Malloc failed\n", info);
		j = 0;
		while (j < TEX_HEIGHT * TEX_WIDTH)
		{
			info->tex[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	load_img(t_info *info, int *tex, char *path, t_img *img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_file_to_image(info->mlx, path,\
			&img->width, &img->height);
	if (!img->img)
		print_error(-1, "Error : Img loading failed\n", info);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,\
			&img->size_l, &img->endian);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			tex[img->width * y + x] = img->data[img->width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_img(info, info->tex[3], info->n_tex_path, &img);
	load_img(info, info->tex[2], info->s_tex_path, &img);
	load_img(info, info->tex[0], info->w_tex_path, &img);
	load_img(info, info->tex[1], info->e_tex_path, &img);
	load_img(info, info->tex[4], info->p_tex_path, &img);
	free(info->n_tex_path);
	free(info->s_tex_path);
	free(info->w_tex_path);
	free(info->e_tex_path);
	free(info->p_tex_path);
}
