/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:28:11 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/20 16:28:14 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_line_element(t_info *info, char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		return (get_screen_size(info, line + 2));
	else if (ft_strncmp(line, "NO ", 3) == 0)
		return (get_texture(info, line + 3, 'N'));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (get_texture(info, line + 3, 'S'));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (get_texture(info, line + 3, 'W'));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (get_texture(info, line + 3, 'E'));
	else if (ft_strncmp(line, "S ", 2) == 0)
		return (get_texture(info, line + 2, 'P'));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (get_color(info, line + 2, 'C'));
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (get_color(info, line + 2, 'F'));
	else if (line[0] == '\0')
		return (1);
	else if (line[0] == ' ' || line[0] == '1')
		return (0);
	print_error(0, "\n", info);
	return (-1);
}

void	parse_cub(t_info *info)
{
	char	*line;
	int		temp;

	while ((temp = get_next_line(info->fd, &line)) > 0)
	{
		if (!parse_line_element(info, line))
			break ;
		free(line);
	}
	if (temp == -1)
		print_error(-1, "Error : Couldn't read file(GNL)\n", info);
	parse_map(info, line);
}
