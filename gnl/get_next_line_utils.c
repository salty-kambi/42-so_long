/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:59:13 by lsuau             #+#    #+#             */
/*   Updated: 2021/11/26 11:55:30 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gft_strlen(const char *s, int n)
{
	size_t	x;

	x = 0;
	if (n == 2)
	{
		while (s[x])
			x++;
		if (x > 0)
			x--;
		if (s[x] == '\n')
			return (1);
		return (0);
	}
	while (s[x])
	{
		if (s[x] == '\n' && n)
			return (x + 1);
		x++;
	}
	return (x);
}

size_t	gft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	x;

	if (dstsize > 0)
	{
		x = 0;
		while (x < dstsize - 1 && src[x])
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = 0;
	}
	return (0);
}

char	*gft_strdup(char *s1, int n)
{
	int		x;
	char	*r;

	x = 0;
	if (!s1[x])
		return (0);
	r = malloc(gft_strlen(s1, n) + 1);
	if (!r)
		return (0);
	gft_strlcpy(r, s1, gft_strlen(s1, n) + 1);
	return (r);
}

char	*gft_strjoin(char **line, char *buff, int n)
{
	char	*r;
	int		size;
	int		x;
	int		y;

	x = gft_strlen(*line, 0);
	y = 0;
	size = gft_strlen(*line, 0) + gft_strlen(buff, n) + 1;
	r = malloc(sizeof(char) * size);
	if (!r)
		return (0);
	gft_strlcpy(r, *line, gft_strlen(*line, 0) + 1);
	while (x + y < size)
	{
		r[x + y] = buff[y];
		y++;
	}
	r[x + y - 1] = 0;
	free(*line);
	*line = 0;
	return (r);
}
