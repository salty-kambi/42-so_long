/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:21:16 by lsuau             #+#    #+#             */
/*   Updated: 2021/11/30 14:44:28 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_exit(t_var *m)
{
	mlx_destroy_window(m->mlx, m->win);
	free_map(m->map, -1);
	exit(0);
	return (0);
}

int	check_path(t_var *m, char c)
{
	if (m->end || c == '1' || (c == 'E' && m->nb_apple))
		return (0);
	return (1);
}
//w = 13 //a = 0 // s = 1 // d = 2 //esc = 53

int	key_hook(int key, t_var *m)
{
	if (key == 13 && check_path(m, m->map[m->loc[1] - 1][m->loc[0]]))
		move_up(m);
	if (key == 1 && check_path(m, m->map[m->loc[1] + 1][m->loc[0]]))
		move_down(m);
	if (key == 0 && check_path(m, m->map[m->loc[1]][m->loc[0] - 1]))
		move_left(m);
	if (key == 2 && check_path(m, m->map[m->loc[1]][m->loc[0] + 1]))
		move_right(m);
	if (key == 53)
		free_exit(m);
	return (0);
}

int	loopage(t_var *m)
{
	mlx_key_hook(m->win, key_hook, m);
	mlx_hook(m->win, 17, 1L << 19, free_exit, m);
	return (0);
}

int	main(int argc, char **argv)
{
	t_var		m;
	t_sprite	s;

	errno = 0;
	if (argc != 2)
	{
		write(1, "Error\n: Incorrect number of argument\n", 37);
		return (1);
	}
	if (map_parse(&m, argv[1]))
	{
		if (errno)
			perror("Error\n");
		return (1);
	}
	game_init(&m, &s);
	mlx_loop_hook(m.mlx, loopage, &m);
	mlx_loop(m.mlx);
}
