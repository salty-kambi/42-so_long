/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:07:19 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/11 18:10:57 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_nbline(const char *fmap)
{
	int		fd;
	int		nb_line;
	int		revolution;
	char	*s;

	fd = open(fmap, O_RDONLY);
	if (fd < 0)
		return (0);
	nb_line = 0;
	revolution = 1;
	while (revolution)
	{
		revolution = 0;
		s = get_next_line(fd);
		if (s)
		{
			nb_line++;
			free(s);
			revolution = 1;
		}
	}
	close(fd);
	if (nb_line < 3)
		write(1, "Error\n: Incorrect map (less than 3 line)\n", 41);
	return (nb_line);
}

char	**free_map(char **map, int x)
{
	if (x == -1)
	{
		x = 0;
		while (map[x])
		{
			free(map[x]);
			x++;
		}
		free(map);
		return (0);
	}
	while (x)
	{
		x--;
		free(map[x]);
	}
	free(map);
	return (0);
}

void	remove_newline(char *s)
{
	int	x;

	x = 0;
	while (s[x])
	{
		if (s[x] == '\n')
			s[x] = 0;
		x++;
	}
}

char	**fill_map(const char *fmap, int nb_line)
{
	char	**map;
	int		x;
	int		fd;

	map = malloc(sizeof(char *) * (nb_line + 1));
	if (!map)
		return (0);
	x = 0;
	fd = open(fmap, O_RDONLY);
	while (x < nb_line)
	{
		map[x] = get_next_line(fd);
		if (!map[x])
			return (free_map(map, x));
		remove_newline(map[x]);
		x++;
	}
	map[x] = 0;
	close(fd);
	return (map);
}

int	map_parse(t_var *m, const char *fmap)
{
	int	nb_line;
	int	x;

	x = ft_strlen(fmap);
	if (x < 5 || ft_strncmp(fmap + x - 4, ".ber", 4))
		return (write(1, "Error\n: Not a .ber file format\n", 31));
	nb_line = get_nbline(fmap);
	m->map = fill_map(fmap, nb_line);
	if (!m->map || map_check_error(m->map, nb_line))
		return (1);
	m->loc[0] = ft_strlen(m->map[0]) * 24;
	m->loc[1] = nb_line * 24;
	return (0);
}
