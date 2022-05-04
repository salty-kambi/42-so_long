/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:31:42 by lsuau             #+#    #+#             */
/*   Updated: 2021/11/30 14:45:03 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_cara(char *c, int *check)
{
	if (*c == '0' || *c == '1')
		return (0);
	if (*c == 'E')
	{
		check[0]++;
		return (0);
	}
	if (*c == 'C')
	{
		check[1]++;
		return (0);
	}
	if (*c == 'P')
	{
		check[2]++;
		if (check[2] > 1)
			*c = '0';
		return (0);
	}
	return (1);
}

int	check_rectangl(char **map)
{
	int	len;
	int	x;

	len = ft_strlen(map[0]);
	x = 0;
	while (map[x])
	{
		if (ft_strlen(map[x]) != len)
			return (write(1, "Error\n: map isn't rectangle\n", 28));
		x++;
	}
	return (0);
}

int	check_one_each(char **map)
{
	int	x;
	int	y;
	int	*check;

	x = 0;
	check = calloc(3, sizeof(int));
	if (!check)
		return (1);
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (check_cara(map[x] + y, check))
				return (error_elem(2));
			y++;
		}
		x++;
	}
	if (!check[0] || !check[1] || !check[2])
		return (error_elem(1));
	free(check);
	return (0);
}

int	check_wall(char **map, int nb_line)
{
	int	len;
	int	x;

	len = ft_strlen(*map);
	x = 0;
	while (map[0][x])
	{
		if (map[0][x] != '1' || map[nb_line - 1][x] != '1')
			return (write(1, "Error\n: map not surrounded by wall\n", 35));
		x++;
	}
	x = 0;
	while (map[x])
	{
		if (map[x][0] != '1' || map[x][len - 1] != '1')
			return (write(1, "Error\n: map not surrounded by wall\n", 35));
		x++;
	}
	return (0);
}

int	map_check_error(char **map, int nb_line)
{
	int	ret;

	ret = 0;
	if (check_rectangl(map) || check_one_each(map) || check_wall(map, nb_line))
	{
		free_map(map, -1);
		return (1);
	}
	return (0);
}
