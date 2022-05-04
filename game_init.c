/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:08:08 by lsuau             #+#    #+#             */
/*   Updated: 2021/11/30 08:58:24 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprite_init(t_var *m, t_sprite *s)
{
	s->tile.img = mlx_xpm_file_to_image(m->mlx, "spr/tile.xpm", s->w, s->h);
	s->tile.addr = mlx_get_data_addr(s->tile.img, &s->tile.bpp, \
	&s->tile.linel, &s->tile.endian);
	s->wall.img = mlx_xpm_file_to_image(m->mlx, "spr/wall.xpm", s->w, s->h);
	s->wall.addr = mlx_get_data_addr(s->wall.img, &s->wall.bpp, \
	&s->wall.linel, &s->wall.endian);
	s->apple.img = mlx_xpm_file_to_image(m->mlx, "spr/apple.xpm", s->w, s->h);
	s->apple.addr = mlx_get_data_addr(s->apple.img, &s->apple.bpp, \
	&s->apple.linel, &s->apple.endian);
	s->exit.img = mlx_xpm_file_to_image(m->mlx, "spr/exit.xpm", s->w, s->h);
	s->exit.addr = mlx_get_data_addr(s->exit.img, &s->exit.bpp, \
	&s->exit.linel, &s->exit.endian);
	s->wpr_d.img = mlx_xpm_file_to_image(m->mlx, "spr/wprD.xpm", s->w, s->h);
	s->wpr_d.addr = mlx_get_data_addr(s->wpr_d.img, &s->wpr_d.bpp, \
	&s->wpr_d.linel, &s->wpr_d.endian);
	s->wpr_u.img = mlx_xpm_file_to_image(m->mlx, "spr/wprU.xpm", s->w, s->h);
	s->wpr_u.addr = mlx_get_data_addr(s->wpr_u.img, &s->wpr_u.bpp, \
	&s->wpr_u.linel, &s->wpr_u.endian);
	s->wpr_l.img = mlx_xpm_file_to_image(m->mlx, "spr/wprL.xpm", s->w, s->h);
	s->wpr_l.addr = mlx_get_data_addr(s->wpr_l.img, &s->wpr_l.bpp, \
	&s->wpr_l.linel, &s->wpr_l.endian);
	s->wpr_r.img = mlx_xpm_file_to_image(m->mlx, "spr/wprR.xpm", s->w, s->h);
	s->wpr_r.addr = mlx_get_data_addr(s->wpr_r.img, &s->wpr_r.bpp, \
	&s->wpr_r.linel, &s->wpr_r.endian);
}

void	display_sprite(t_var *m, t_sprite *s, int x, int y)
{
	if (m->map[x][y] == '0')
		mlx_put_image_to_window(m->mlx, m->win, s->tile.img, y * 24, x * 24);
	if (m->map[x][y] == '1')
		mlx_put_image_to_window(m->mlx, m->win, s->wall.img, y * 24, x * 24);
	if (m->map[x][y] == 'E')
		mlx_put_image_to_window(m->mlx, m->win, s->exit.img, y * 24, x * 24);
	if (m->map[x][y] == 'C')
	{
		m->nb_apple++;
		mlx_put_image_to_window(m->mlx, m->win, s->tile.img, y * 24, x * 24);
		mlx_put_image_to_window(m->mlx, m->win, s->apple.img, y * 24, x * 24);
	}
	if (m->map[x][y] == 'P')
	{
		m->map[x][y] = '0';
		m->loc[0] = y;
		m->loc[1] = x;
		mlx_put_image_to_window(m->mlx, m->win, s->tile.img, y * 24, x * 24);
		mlx_put_image_to_window(m->mlx, m->win, s->wpr_d.img, y * 24, x * 24);
	}
}

void	display_map(t_var *m, t_sprite *s)
{
	int	x;
	int	y;

	x = 0;
	m->nb_apple = 0;
	while (m->map[x])
	{
		y = 0;
		while (m->map[x][y])
		{
			display_sprite(m, s, x, y);
			y++;
		}
		x++;
	}
}

int	game_init(t_var *m, t_sprite *s)
{
	m->mlx = mlx_init();
	if (!m->mlx)
		return (1);
	sprite_init(m, s);
	m->win = mlx_new_window(m->mlx, m->loc[0], m->loc[1], "so_long");
	display_map(m, s);
	m->s = s;
	m->step = 0;
	m->end = 0;
	return (0);
}
