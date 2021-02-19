/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohchoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 00:55:41 by soohchoi          #+#    #+#             */
/*   Updated: 2020/12/09 01:04:33 by soohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_screen_size(t_info *info, char *line)
{
	char	**size;

	if (info->width || info->height)
		print_error(0, "(resolution)\n", info);
	size = ft_split(line, ' ');
	if (!size || !size[0] || !size[1] || size[2])
	{
		free_2d(size);
		print_error(0, "(resolution)\n", info);
	}
	info->width = ft_atoi(size[0]);
	info->height = ft_atoi(size[1]);
	free_2d(size);
	if (info->width <= 0 || info->height <= 0)
		print_error(0, "(resolution)\n", info);
	if (info->width > WIN_WIDTH)
		info->width = WIN_WIDTH;
	if (info->height > WIN_HEIGHT)
		info->height = WIN_HEIGHT;
	return (1);
}

int	get_texture(t_info *info, char *line, char c)
{
	skip_space(&line);
	if (!check_name(line, ".xpm"))
		print_error(0, "(texture)\n", info);
	if (c == 'N' && !info->n_tex_path)
		info->n_tex_path = ft_strdup(line);
	else if (c == 'S' && !info->s_tex_path)
		info->s_tex_path = ft_strdup(line);
	else if (c == 'W' && !info->w_tex_path)
		info->w_tex_path = ft_strdup(line);
	else if (c == 'E' && !info->e_tex_path)
		info->e_tex_path = ft_strdup(line);
	else if (c == 'P' && !info->p_tex_path)
		info->p_tex_path = ft_strdup(line);
	else
		print_error(0, "(texture)\n", info);
	return (1);
}

int	get_rgb(char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (65536 * r + 256 * g + b);
}

int	get_color(t_info *info, char *line, char c)
{
	char	**rgb;
	int		color;

	skip_space(&line);
	rgb = ft_split(line, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		print_error(0, "(color)\n", info);
	color = get_rgb(rgb);
	free_2d(rgb);
	rgb = 0;
	if (color == -1)
		print_error(0, "(color)\n", info);
	if (c == 'F' && info->floor == -1)
		info->floor = color;
	else if (c == 'C' && info->ceil == -1)
		info->ceil = color;
	else
		print_error(0, "(color)\n", info);
	return (1);
}
