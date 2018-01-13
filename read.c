/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:34:27 by yusong            #+#    #+#             */
/*   Updated: 2017/11/16 15:34:29 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	map_read(t_fil *fill)
{
	int i;
	char *buf;
	char **split;
	//while (!get_next_line(0, &buf) != 1)
	if (get_next_line(0, &buf) == 1)
	{
		if (DEBUG_FLAG)
		{
			write(fill->fd, buf, ft_strlen(buf));
			write(fill->fd, "\n", 1);
		}
		split = ft_strsplit(buf, ' ');
		fill->map_h = ft_atoi(split[1]);
		fill->map_w = ft_atoi(split[2]);
		free(split[0]);
		free(split[1]);
		free(split[2]);
		free(split);
		free(buf);
	}
	else
	{
		fill->exit = 0;
		return ;
	}
	i = 0;
	fill->map_cur = (char**)malloc(sizeof(char*) * (fill->map_h + 1));
	while (i <= fill->map_h)
	{
		if (get_next_line(0, fill->map_cur + i) != 1)
		{
			fill->exit = 0;
			return ;
		}
		if (DEBUG_FLAG)
		{
			write(fill->fd, fill->map_cur[i], ft_strlen(fill->map_cur[i]));
			write(fill->fd, "MAP\n", 4);
		}
		i++;
	}
	tetris_read(fill);
}

void  tetris_read(t_fil *fill)
{
	char	*buf;
	char	**split;
	int		i;

	if (get_next_line(0, &buf) == 1)
	{
		if (DEBUG_FLAG)
		{
			write(fill->fd, buf, ft_strlen(buf));
			write(fill->fd, "TET_READ\n", 9);
		}
		split = ft_strsplit(buf, ' ');
		fill->tet_h = ft_atoi(split[1]);
		fill->tet_w = ft_atoi(split[2]);
		free(split[0]);
		free(split[1]);
		free(split[2]);
		free(split);
		free(buf);
	}
	else
	{
		fill->exit = 0;
		return ;
	}
	i = 0;
	fill->tetris = (char**)malloc(sizeof(char*) * fill->tet_h);
	while (i < fill->tet_h)
	{
		if(get_next_line(0, fill->tetris + i) != 1)
		{
			fill->exit = 0;
			return ;
		}
		if (DEBUG_FLAG)
		{
			write(fill->fd, fill->tetris[i], ft_strlen(fill->tetris[i]));
			write(fill->fd, "TET_READ\n", 9);
		}
		i++;
	}
}
