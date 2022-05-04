/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 08:21:39 by lsuau             #+#    #+#             */
/*   Updated: 2021/11/30 09:04:47 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_var *m, void *s, int x, int y)
{
	mlx_put_image_to_window(m->mlx, m->win, s, x * 24, y * 24);
}

void	move_up(t_var *m)
{
	put_image(m, m->s->tile.img, m->loc[0], m->loc[1]);
	m->loc[1]--;
	if (m->map[m->loc[1]][m->loc[0]] == 'C')
	{
		m->map[m->loc[1]][m->loc[0]] = '0';
		m->nb_apple--;
		put_image(m, m->s->tile.img, m->loc[0], m->loc[1]);
		put_image(m, m->s->wpr_u.img, m->loc[0], m->loc[1]);
	}
	else if (m->map[m->loc[1]][m->loc[0]] == '0')
		put_image(m, m->s->wpr_u.img, m->loc[0], m->loc[1]);
	else
		m->end = 1;
	write(1, "step : ", 7);
	m->step++;
	ft_putnbr(m->step);
	write(1, "\n", 1);
}

void	move_down(t_var *m)
{
	put_image(m, m->s->tile.img, m->loc[0], m->loc[1]);
	m->loc[1]++;
	if (m->map[m->loc[1]][m->loc[0]] == 'C')
	{
		m->map[m->loc[1]][m->loc[0]] = '0';
		m->nb_apple--;
		put_image(m, m->s->tile.img, m->loc[0], m->loc[1]);
		put_image(m, m->s->wpr_d.img, m->loc[0], m->loc[1]);
	}
	else if (m->map[m->loc[1]][m->loc[0]] == '0')
		put_image(m, m->s->wpr_d.img, m->loc[0], m->loc[1]);
	else
		m->end = 1;
	write(1, "step : ", 7);
	m->step++;
	ft_putnbr(m->step);
	write(1, "\n", 1);
}

void	move_left(t_var *m)
{
	put_image(m, m->s->tile.img, m->loc[0], m->loc[1]);
	m->loc[0]--;
	if (m->map[m->loc[1]][m->loc[0]] == 'C')
	{
		m->map[m->loc[1]][m->loc[0]] = '0';
		m->nb_apple--;
		put_image(m, m->s->tile.img, m->loc[0], m->loc[1]);
		put_image(m, m->s->wpr_l.img, m->loc[0], m->loc[1]);
	}
	else if (m->map[m->loc[1]][m->loc[0]] == '0')
		put_image(m, m->s->wpr_l.img, m->loc[0], m->loc[1]);
	else
		m->end = 1;
	write(1, "step : ", 7);
	m->step++;
	ft_putnbr(m->step);
	write(1, "\n", 1);
}

void	move_right(t_var *m)
{
	put_image(m, m->s->tile.img, m->loc[0], m->loc[1]);
	m->loc[0]++;
	if (m->map[m->loc[1]][m->loc[0]] == 'C')
	{
		m->map[m->loc[1]][m->loc[0]] = '0';
		m->nb_apple--;
		put_image(m, m->s->tile.img, m->loc[0], m->loc[1]);
		put_image(m, m->s->wpr_r.img, m->loc[0], m->loc[1]);
	}
	else if (m->map[m->loc[1]][m->loc[0]] == '0')
		put_image(m, m->s->wpr_r.img, m->loc[0], m->loc[1]);
	else
		m->end = 1;
	write(1, "step : ", 7);
	m->step++;
	ft_putnbr(m->step);
	write(1, "\n", 1);
}
