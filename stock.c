/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:23:11 by lsuau             #+#    #+#             */
/*   Updated: 2021/11/30 14:42:04 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*r;
	size_t	x;

	x = 0;
	r = malloc(size * count);
	if (!r)
		return (0);
	while (x < (size * count))
	{
		r[x] = 0;
		x++;
	}
	return (r);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	x;

	x = 0;
	if (n < 1)
		return (0);
	while (s1[x] && s2[x] && (s1[x] == s2[x]) && n > 0)
	{
		n--;
		if (n > 0)
			x++;
	}
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}

void	ft_putnbr(int n)
{
	int	nbw;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n >= 0 && n < 10)
	{
		nbw = n + '0';
		write(1, &nbw, 1);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(n * (-1));
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	error_elem(int n)
{
	if (n == 1)
	{
		write(1, "Error\n: Incorrect map, not enough collectible, ", 47);
		write(1, "starting position or exit\n", 26);
	}
	if (n == 2)
	{
		write(1, "Error\n: Incorrect map, there is ", 32);
		write(1, "an unsupported character\n", 25);
	}
	return (1);
}
