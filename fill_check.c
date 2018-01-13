/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:17:36 by hkang             #+#    #+#             */
/*   Updated: 2018/01/10 11:17:40 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int  fill_tet_check(t_fil *fill, int x, int y)
{
	int tx;
	int ty;
	int count;

	ty = 0;
	count = 0;
	fill->calc = 0;
	while (ty < fill->tet_h)
	{
		tx = 0;
		while (tx < fill->tet_w)
		{
			if (fill->tetris[ty][tx] == '*' &&
					(count >= 2 || tx + x < 4 || ty + y < 1 || tx + x - 4 >= fill->map_w || ty + y - 1 >= fill->map_h ||
					fill->map_cur[ty + y][tx + x] == fill->enemy_char ||
					fill->map_cur[ty + y][tx + x] == fill->enemy_char + 32))
				return (0);
			else if(fill->tetris[ty][tx] == '*' &&
						(fill->map_cur[ty + y][tx + x] == fill->me_char ||
						fill->map_cur[ty + y][tx + x] == fill->me_char + 32))
			{
				count++;
				fill->calc += fill->value[ty + y - 1][tx + x - 4];
			}
			else if (fill->tetris[ty][tx] == '*')
				fill->calc += fill->value[ty + y - 1][tx + x - 4];
			tx++;
		}
		ty++;
	}
	if (count == 1)
		return (1);
	return (0);
}

void get_min(t_fil *fill, int x, int y)
{
	if (fill->calc < fill->min)
	{
		fill->min = fill->calc;
		fill->putx = x - 4;
		fill->puty = y - 1;
	}
}

void  fill_check(t_fil *fill)
{
	int map[2];
	int	test;

	fill->min = 1000000000;
	map[0] = 1 - fill->tet_h;
	while (map[0] < fill->map_h + 1)
	{
		map[1] = 4 - fill->tet_w;
		while (map[1] < fill->map_w + 4)
		{

			test = 0;
			test = fill_tet_check(fill, map[1], map[0]);
			if(test)
				get_min(fill, map[1], map[0]);
			map[1]++;
		}
		map[0]++;
	}
	if (fill->min == 1000000000)
		fill->exit = 0;
}
