/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohchoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 00:57:05 by soohchoi          #+#    #+#             */
/*   Updated: 2020/12/09 01:22:15 by soohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_map(t_info *info, t_list *lst)
{
	int		i;
	int		j;
	char	*line;
	int		dir_count;

	i = -1;
	dir_count = 0;
	while (++i < info->map_height)
	{
		line = (char *)lst->content;
		j = (int)ft_strlen(line);
		while (--j >= 0)
		{
			if (!is_map_arg(line[j]))
				print_error(1, "(invalid character)\n", info);
			info->map[i][info->map_width - 1 - j] = line[j];
			count_arg(info, i, info->map_width - 1 - j, &dir_count);
		}
		lst = lst->next;
	}
	if (dir_count == 0 || dir_count > 1)
		print_error(1, "(direction declaration error)\n", info);
}

int		get_max_line_size(t_list *lst)
{
	int	max;
	int	size;

	max = 0;
	while (lst)
	{
		size = ft_strlen((char *)lst->content);
		if (size > max)
			max = size;
		lst = lst->next;
	}
	return (max);
}

void	init_map(t_info *info, t_list *lst)
{
	int	i;
	int	j;

	info->map_height = ft_lstsize(lst);
	if (!(info->map = (char **)malloc(sizeof(char *) * (info->map_height))))
		print_error(1, "(malloc failed)\n", info);
	i = 0;
	info->map_width = get_max_line_size(lst);
	while (lst)
	{
		if (!(info->map[i] = (char *)malloc(info->map_width + 1)))
			print_error(1, "(malloc failed)\n", info);
		j = 0;
		while (j < info->map_width)
			info->map[i][j++] = ' ';
		info->map[i][info->map_width] = '\0';
		i++;
		lst = lst->next;
	}
}

void	parse_map(t_info *info, char *line)
{
	t_list	*lst;
	int		temp;

	lst = ft_lstnew(ft_strdup(line));
	free(line);
	while ((temp = get_next_line(info->fd, &line)) > 0)
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	if (temp == -1)
		print_error(-1, "Error : Couldn't read file(GNL)\n", info);
	close(info->fd);
	info->fd = -1;
	if (line[0])
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(line)));
	free(line);
	init_map(info, lst);
	fill_map(info, lst);
	ft_lstclear(&lst, free);
}
