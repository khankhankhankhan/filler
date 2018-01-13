/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 10:40:09 by hkang             #+#    #+#             */
/*   Updated: 2017/10/23 16:03:45 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*find_it(t_file **save, const int fd, int *rd)
{
	t_file	*last;
	t_file	*temp;

	temp = *save;
	last = temp;
	while (temp && last->file != fd)
	{
		last = temp;
		temp = temp->next;
	}
	if (last->file == fd)
		temp = last;
	else
	{
		temp = (t_file*)malloc(sizeof(t_file));
		if (!temp)
			return (0);
		temp->ch = ft_strnew(BUFF_SIZE);
		temp->file = fd;
		temp->next = NULL;
		last->next = temp;
	}
	if (temp->ch[0] == '\0')
		*rd = read(fd, temp->ch, BUFF_SIZE);
	return (temp);
}

void	get_line(char **line, char *buf)
{
	char *last;

	last = *line;
	*line = ft_strjoin(*line, buf);
	free(last);
}

int		get_it(int *rd, t_file **temp, char **line, const int fd)
{
	int		i;

	i = 0;
	while (*rd != 0 && (*temp)->ch[i] != '\n')
	{
		if (i == BUFF_SIZE || (*temp)->ch[i] == '\0')
		{
			get_line(line, (*temp)->ch);
			ft_bzero((*temp)->ch, BUFF_SIZE);
			*rd = read(fd, (*temp)->ch, BUFF_SIZE);
			if (*rd < 0)
				return (-1);
			i = -1;
		}
		i++;
	}
	if ((*temp)->ch[i] == '\n' || (*temp)->ch[i] == '\0')
	{
		(*temp)->ch[i] = '\0';
		get_line(line, (*temp)->ch);
		(*temp)->ch = ((char*)ft_memcpy((*temp)->ch,
						((*temp)->ch + i + 1), BUFF_SIZE - i));
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_file	*save;
	t_file			*temp;
	int				rd;

	rd = 1;
	if (fd < 0 || !line)
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	if (!save)
	{
		save = (t_file*)malloc(sizeof(t_file));
		save->ch = ft_strnew(BUFF_SIZE);
		save->file = fd;
		save->next = NULL;
	}
	temp = find_it(&save, fd, &rd);
	if (rd == 0)
		return (0);
	if (rd < 0)
		return (-1);
	return (get_it(&rd, &temp, line, fd));
}
