/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 11:36:25 by hkang             #+#    #+#             */
/*   Updated: 2017/10/19 11:16:49 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define BUFF_SIZE 15

typedef struct	s_filelist
{
	char				*ch;
	int					file;
	struct s_filelist	*next;
}				t_file;

int				get_next_line(const int fd, char **line);
t_file			*find_it(t_file **save, const int fd, int *rd);
t_file			*find_it(t_file **save, const int fd, int *rd);
void			get_line(char **line, char *buf);

#endif
