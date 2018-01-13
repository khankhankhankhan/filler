/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:36:58 by hkang             #+#    #+#             */
/*   Updated: 2018/01/08 15:37:02 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# define DEBUG_FLAG 1

typedef struct s_filler
{
	char	**map_cur;
	int		**value;
	int		map_h;
	int		map_w;
	int		me_x;
	int		me_y;
	int		enemy_x;
	int		enemy_y;
	char	me_char;
	char	me_lchar;
	char	enemy_char;
	char	**tetris;
	int		tet_h;
	int		tet_w;
	int		fd;
	int		putx;
	int		puty;
	int		min;
	int		calc;
	int		exit;
}		t_fil;

void	map_read(t_fil *fill);
void  fill_init(t_fil *fill);
void  tetris_read(t_fil *fill);
void fill_initvm(t_fil *fill);
void fill_free(t_fil *fill);
void fill_analyze(t_fil *fill);
void creat_table(t_fil *fill);
void fill_find(t_fil *fill);

void  fill_check(t_fil *fill);
int  fill_tet_check(t_fil *fill, int x, int y);
void get_min(t_fil *fill, int x, int y);

#endif
