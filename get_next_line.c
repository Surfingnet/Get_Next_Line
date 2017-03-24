/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghazari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:09:19 by mghazari          #+#    #+#             */
/*   Updated: 2017/03/24 17:18:41 by mghazari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	concat(char *str1, char *str2)
{
	char	*tmp;

	while (!(tmp = ft_strjoin(str1, str2)))
		continue;
	ft_strdel(&str1);
	str1 = tmp;
}

/*
 * Return the last saved buffer for a specified fd or make a new one if there is not any saved buffer for this fd and return it. If error, return NULL.
 */
static char	*buff_list(t_list *file, int fd)
{
	t_list	*tmp;

	tmp = file;
	while ((int)tmp->content_size != fd)
		if(tmp->next)
			tmp = tmp->next;
		else
			break;
	if ((int)tmp->content_size == fd)
		return ((char*)tmp->content);
	if (!(tmp = ft_lstnew(ft_strnew(BUFF_SIZE), BUFF_SIZE + 1)))
		return (NULL);
	tmp->content_size = fd;
	ft_lstadd(&file, tmp);
	return ((char*)file->content);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*saved_buffers;
	char			*last_buffer;
	int				ret;
	char			*buf;
	char			*tmp;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	if (!saved_buffers)
		saved_buffers = ft_lstnew(ft_strnew(0), 1);
	if (!line)
		return (-1);
	if (*line)
		ft_strdel(line);
	last_buffer = buff_list(saved_buffers, fd);
	if (!last_buffer && !(*line = ft_strnew(0)))
		return (-1);
	ret = 1;
	if (last_buffer[0] != '\0')//if last buffer is not empty
	{
		if ((tmp = ft_strchr(last_buffer, (int)'\n')))
			buf = ft_strcpy(buf, last_buffer);
		else
		{
			concat(*line, last_buffer);
			while ((ret = read(fd, buf, BUFF_SIZE)) && !(tmp = ft_memchr((void*)buf,(int)'\n', BUFF_SIZE)))
				concat(*line, buf);
		}
		if (ret <= 0 )
			return (ret);
		last_buffer = ft_strcpy(last_buffer, &(tmp[1]));
		ft_strclr(tmp);
		concat(*line, buf);
		return (1);
	}
	else
	{
		while ((ret = read(fd, buf, BUFF_SIZE)) && !(tmp = ft_memchr((void*)buf,(int)'\n', BUFF_SIZE)))
				concat(*line, buf);
		if (ret <= 0 )
			return (ret);
		last_buffer = ft_strcpy(last_buffer, &(tmp[1]));
		ft_strclr(tmp);
		concat(*line, buf);
		return (1);
	}
	return (0);
}
