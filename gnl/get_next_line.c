/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:24:40 by lsuau             #+#    #+#             */
/*   Updated: 2021/11/25 14:50:26 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_newline(char *buff, char **line)
{
	int	x;

	x = 0;
	while (buff[x])
	{
		if (buff[x] == '\n')
		{
			if (*line)
				*line = gft_strjoin(line, buff, 0);
			else
				*line = gft_strdup(buff, 0);
			return (1);
		}
		x++;
	}
	if (*line)
		*line = gft_strjoin(line, buff, 0);
	else
		*line = gft_strdup(buff, 0);
	if (!*line)
		return (1);
	return (0);
}

int	ft_memorage(char **line, char *buff)
{
	int		x;
	char	*d;

	x = 1;
	while (*line && (*line)[x])
	{
		if ((*line)[x - 1] == '\n')
		{
			d = *line;
			gft_strlcpy(buff, *line + x, BUFFER_SIZE + 1);
			*line = gft_strdup(*line, 1);
			free(d);
			return (1);
		}
		x++;
	}
	buff[0] = 0;
	if (!*line)
		return (1);
	return (0);
}

int	ft_buffcheck(char *buff, char **line)
{
	int		x;

	x = 0;
	if (!buff[x])
		return (0);
	while (buff[x])
	{
		if (buff[x] == '\n')
		{
			*line = gft_strdup(buff, 1);
			if (!*line)
				return (1);
			gft_strlcpy(buff, buff + x + 1, BUFFER_SIZE + 1);
			return (gft_strlen(*line, 2));
		}
		x++;
	}
	*line = gft_strdup(buff, 1);
	if (!line)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE + 1];
	char			*line[1];
	int				x;

	*line = 0;
	if (BUFFER_SIZE < 1 || fd < 0 || ft_buffcheck(buff, line))
		return (*line);
	x = read(fd, buff, BUFFER_SIZE);
	while (x > 0)
	{
		buff[x] = 0;
		if (ft_check_newline(buff, line))
		{
			ft_memorage(line, buff);
			return (*line);
		}
		x = read(fd, buff, BUFFER_SIZE);
	}
	if (x < 0)
		return (0);
	buff[0] = 0;
	return (*line);
}
