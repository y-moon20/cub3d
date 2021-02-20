/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:06:33 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/19 18:06:59 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	split_line(char **str, char **line)
{
	char		*point;
	char		*temp;

	if ((point = ft_strchr(*str, '\n')) != NULL)
	{
		*line = ft_strndup(*str, point - *str);
		temp = ft_strndup(point + 1, ft_strlen(point + 1));
		if (*str != 0)
			free(*str);
		*str = temp;
		return (RETURN_LINE);
	}
	else
	{
		*line = ft_strndup(*str, ft_strlen(*str));
		free(*str);
		*str = 0;
		return (RETURN_EOF);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		*buf;
	char		*temp;
	int			read_size;

	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (RETURN_ERROR);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (RETURN_ERROR);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[read_size] = '\0';
		temp = ft_strjoin(backup[fd], buf);
		if (backup[fd])
			free(backup[fd]);
		backup[fd] = temp;
		if (ft_strchr(backup[fd], '\n') || read_size == 0)
			break ;
	}
	free(buf);
	buf = 0;
	if (read_size == -1)
		return (RETURN_ERROR);
	return (split_line(&backup[fd], line));
}
