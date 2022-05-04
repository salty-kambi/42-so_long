/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:22:20 by lsuau             #+#    #+#             */
/*   Updated: 2021/11/25 14:51:45 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
size_t	gft_strlen(const char *s, int n);
size_t	gft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*gft_strdup(char *s1, int n);
char	*gft_strjoin(char **line, char *buff, int n);
int		ft_check_newline(char *buff, char **line);
int		ft_memorage(char **line, char *buff);
int		ft_buffcheck(char *buff, char **line);

#endif