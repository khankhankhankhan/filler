/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:00:39 by hkang             #+#    #+#             */
/*   Updated: 2018/01/09 16:00:42 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void fill_find(t_fil *fill)
{
	int i;
	int j;

	j = 1;
	while(j <= fill->map_h)
	{
		i = 4;
		while(i < fill->map_w)
		{
			if(fill->map_cur[j][i] == fill->enemy_char + 32 ||
					fill->map_cur[j][i] == fill->enemy_char)
			{
				fill->enemy_x = i - 4;
				fill->enemy_y = j - 1;
			}
			if(fill->map_cur[j][i] == fill->me_char + 32 ||
					fill->map_cur[j][i] == fill->me_char)
			{
				fill->me_x = i - 4;
				fill->me_y = j - 1;
			}
			i++;
		}
		j++;
	}
}

void creat_table(t_fil *fill)
{
		int i;
		int j;

		fill->value = (int**)malloc(sizeof(int*) * fill->map_h);
		j = 0;
		while (j < fill->map_h)
		{
			i = 0;
			fill->value[j] = (int*)malloc(sizeof(int) * fill->map_w);
			while (i < fill->map_w)
			{
				fill->value[j][i] = (i < fill->enemy_x) ? fill->enemy_x - i : i - fill->enemy_x;
				fill->value[j][i] += (j < fill->enemy_y) ? fill->enemy_y - j : j - fill->enemy_y;

				/*if (DEBUG_FLAG)
				{
					ft_putnbr_fd(fill->value[j][i], fill->fd);
					write(fill->fd, ", ", 2);
				}*/
				i++;
			}
			/*if (DEBUG_FLAG)
				write(fill->fd, "\n", 1);*/
			j++;
		}
}

void fill_analyze(t_fil *fill)
{
	//fill_find(fill);
	//creat_table(fill);
	fill_check(fill);
}
