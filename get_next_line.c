/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_Next_Line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghazari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:09:19 by mghazari          #+#    #+#             */
/*   Updated: 2017/04/18 14:59:43 by mghazari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_buff	*crea_lst(t_buff **buff, int fd, int chk)
{
	t_buff		*new;

	if (!(new = malloc(sizeof(t_buff))))
		return (NULL);
	new->fd = fd;
	new->ind = -1;
	new->buff = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	if (chk)
	{
		new->next = *buff;
		*buff = new;
		return (new);
	}
	return (new);
}

static t_buff	*check_buff(t_buff **cpy, int fd)
{
	while (*cpy)
	{
		if ((*cpy)->fd == fd)
			return (*cpy);
		*cpy = (*cpy)->next;
	}
	return (NULL);
}

static int		clean_buff(t_buff *cpy, char **line, int fd)
{
	int		i;

	i = cpy->ind;
	if (i == -1)
		i = 0;
	while (cpy->buff[i])
	{
		if (cpy->buff[i] == '\n' || cpy->buff[i] == '\0')
		{
			*line = ft_strjoinf(*line,\
					ft_strsub(cpy->buff, 0, i), 3);
			cpy->buff = ft_strsubf(cpy->buff, i + 1,\
					ft_strlen(cpy->buff));
			cpy->ind = 0;
			return (1);
		}
		i++;
	}
	*line = ft_strdup(cpy->buff);
	cpy->buff = ft_strnew(BUFF_SIZE);
	return (read_file(cpy, line, fd));
}

int				read_file(t_buff *cpy, char **line, int fd)
{
	int				i;
	int				ret;

	i = 0;
	ret = 0;
	while ((ret = read(fd, cpy->buff, BUFF_SIZE)) > 0)
	{
		cpy->buff[ret] = '\0';
		if (ft_strchr(cpy->buff, '\n') != NULL)
			return (clean_buff(cpy, line, fd));
		*line = ft_strjoinf(*line, cpy->buff, 1);
	}
	if (ret == -1)
		return (-1);
	if (*line[0] == 0)
		return (0);
	if (ret < BUFF_SIZE)
		free(cpy->buff);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_buff	*buff;
	t_buff			*cpy;

	if (line == NULL || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!buff)
		buff = crea_lst(NULL, fd, 0);
	cpy = buff;
	if (!check_buff(&cpy, fd))
		cpy = crea_lst(&buff, fd, 1);
	*line = ft_strnew(0);
	if (cpy->ind != -1)
		if (clean_buff(cpy, line, fd))
			return (1);
	return (read_file(cpy, line, fd));
}
