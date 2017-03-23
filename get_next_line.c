/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_Next_Line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghazari <mghazari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 09:40:20 by mghazari          #+#    #+#             */
/*   Updated: 2017/03/23 18:12:23 by mghazari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	concatenate(char *str1, char *str2)
{
	size_t	size;
	char	*dest;
	
	if (str1)
	{
		ft_putstr("destination string before strncat: \"");
		ft_putendl(str1);
	}
	if (!str1)
		while (!(str1 = ft_strnew(0)))
			continue;
	size = ft_strlen(str1) + ft_strlen(str2) + 1;
	while (!(dest = ft_strnew(size)))
		continue;
	ft_strcat(dest, str1);
	ft_strcat(dest, str2);
	str1 = dest;
	ft_putstr("destination string after strncat: \"");
	ft_putstr(str1);
	ft_putendl("\"");
	return (0);
}

/*
 *delete first line of a string
 */
static void	*del_line(char *str)
{
	int		i;
	int		newlen;
	char	*newstr;

	i = -1;
	while (str[++i] && str[i] != '\n')
		continue;
	if (!str[i])
		return (NULL);
	newlen = ft_strlen(str) - (i + 1);
	while (!(newstr = (char*)ft_memalloc(newlen + 1)))
		continue;
	ft_reverse(str, ft_strlen(str));
	ft_reverse(ft_strncpy(newstr, str, newlen), newlen);
	return (NULL);
}

/*
 *return last buffer if known fd or a new string if not
 */
static char *buff_list(t_list *file, int fd)
{
	t_list	*tmp;

	tmp = file;
	while ((int)tmp->content_size != fd)
		if (tmp->next)
		{
			ft_putendl("1");
			tmp = tmp->next;
		}
		else
		{
			ft_putendl("2");
			break;
		}
	if ((int)tmp->content_size == fd)
		{
			ft_putendl(">found in history");
			return ((char*)tmp->content);
		}
	ft_putendl(">not found in history");
	while (!(tmp = ft_lstnew(ft_strnew(BUFF_SIZE), BUFF_SIZE + 1)))
		continue;
	tmp->content_size = (size_t)fd;
	ft_lstadd(&file, tmp);
	ft_putendl(">done");
	return ((char*)tmp->content);
}

/*
 *
 */
static int cpy_line(char *buf, char *dest)
{
	int	i;

	i = -1;
	while (buf[++i] && buf[i] != '\n')
		dest[i] = buf[i];
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static	t_list	*fds;
	int				ret;
	char	buf[BUFF_SIZE + 1];
	char	tmp[BUFF_SIZE + 1];
	
	ft_putendl("checking file");
	
	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);

	ft_putendl(">ok");
	ft_putendl("checking destination ptr");

	if (*line)
		ft_strdel(line);

	ft_putendl(">ok");
	ft_putendl("checking history");
	if (!fds)
		fds = ft_lstnew(ft_strnew(0), 1);
	ft_putendl(">ok");
	ft_putendl("looking for existing buffer in history");

	if (cpy_line(buff_list(fds, fd), tmp))
	{
		ft_putendl(">found");
		del_line(buff_list(fds, fd));
		concatenate(*line, tmp);
		ft_putendl(">line transmitted");
		return (1);
	}
	ft_putendl(">not found\nfilling buffer until EOL/EOF");
	while ((ret = read(fd, buf, BUFF_SIZE)) && !ft_memchr((const void*)buf, (int)'\n', BUFF_SIZE))
	{
		buf[ret] = '\0';
		ft_putstr(">transmitting buffer to destination \n(buffer: \"");
		ft_putstr(buf);
		ft_putendl("\")");
		concatenate(*line, buf);
	}
	ft_putendl("EOL/EOF reached \n(buffer: \"");
	ft_putendl(buf);
	ft_putendl("\")");
	if (ret != 0)
	{
		ft_putendl("copying first line from the buffer into tmp");
		cpy_line(buf, tmp);
		ft_putendl("deleting fist line of the buffer");
		del_line(buf);
		ft_putendl("saving buffer into list");
		ft_strcpy(buff_list(fds, fd), buf);
		ft_putendl("transmitting tmp into destination");
		concatenate(*line, tmp);
		ft_putendl("finished");
	}
	return (ret == -1 ? -1 : (ret != 0));
}
