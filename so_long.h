/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:40:50 by lsuau             #+#    #+#             */
/*   Updated: 2021/11/30 14:38:28 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include <stdio.h>
# include "mlx/mlx.h"
# include <errno.h>

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		linel;
	int		endian;
	int		*w;
	int		*h;
}				t_img;

typedef struct s_sprite {
	t_img	tile;
	t_img	wall;
	t_img	apple;
	t_img	exit;
	t_img	wpr_u;
	t_img	wpr_d;
	t_img	wpr_l;
	t_img	wpr_r;
	int		w[1];
	int		h[1];
}				t_sprite;

typedef struct s_var {
	void		*mlx;
	void		*win;
	t_sprite	*s;
	char		**map;
	int			loc[2];
	int			nb_apple;
	int			step;
	int			end;
}				t_var;

int		map_parse(t_var *m, const char *fmap);
char	**free_map(char **map, int x);
int		map_check_error(char **map, int nb_line);
int		game_init(t_var *m, t_sprite *s);
void	sprite_init(t_var *m, t_sprite *s);
void	move_up(t_var *m);
void	move_down(t_var *m);
void	move_left(t_var *m);
void	move_right(t_var *m);
int		ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putnbr(int n);
int		error_elem(int n);

#endif