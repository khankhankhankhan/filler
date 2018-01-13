/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:27:17 by hkang             #+#    #+#             */
/*   Updated: 2018/01/08 14:27:20 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void  fill_init(t_fil *fill)
{
	fill->me_x = 0;
	fill->me_y = 0;
	fill->enemy_x = 0;
	fill->enemy_y = 0;
	fill->exit = 1;
	fill->putx = -1;
	fill->puty = -1;
}

void fill_initvm(t_fil *fill)
{
	char	*line;

	while(!ft_strstr(line, "hkang.filler"))
	{
		get_next_line(0, &line);
	}
	if (ft_strstr(line, "hkang.filler"))
	{
		if (line[10] == '1')
		{
			fill->me_char = 'O';
			fill->enemy_char = 'X';
			free(line);
			return ;
		}
		else if (line[10] == '2')
		{
			fill->me_char = 'X';
			fill->enemy_char = 'O';
			free(line);
			return ;
		}
	}
	write(1, "BAD PLAYER\n", 11);
}
void fill_free(t_fil *fill)
{
	int i;

	i = 0;
	while (i <= fill->map_h)
	{
		free(fill->map_cur[i]);
		i++;
	}
	free(fill->map_cur);
	i = 0;
	while (i < fill->tet_h)
	{
		free(fill->tetris[i]);
		i++;
	}
	free(fill->tetris);
}

int		main(void)
{
	t_fil fill;
	if (DEBUG_FLAG)
		fill.fd = open("filler.log", O_RDWR | O_TRUNC | O_CREAT | O_APPEND, 500);
	fill_initvm(&fill);
	fill_init(&fill);

	map_read(&fill);
	if (fill.exit == 0)
		return (0);
	fill_find(&fill);
	creat_table(&fill);

	while (fill.exit)
	{
		fill_analyze(&fill);
		if (fill.exit == 0)
			return (0);
		if (DEBUG_FLAG)
		{
			ft_putnbr_fd(fill.puty, fill.fd);
			write(fill.fd, ", ", 2);
			ft_putnbr_fd(fill.putx, fill.fd);
			write(fill.fd, "\n", 1);
		}
		ft_putnbr(fill.puty);
		write(1, " ", 1);
		ft_putnbr(fill.putx);
		write(1, "\n", 1);
		fill_free(&fill);
		map_read(&fill);
	}
	if (DEBUG_FLAG)
		close(fill.fd);
	return (0);
}
