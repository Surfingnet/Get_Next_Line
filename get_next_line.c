/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_Next_Line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghazari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:09:19 by mghazari          #+#    #+#             */
/*   Updated: 2017/04/15 13:04:40 by mghazari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strsubf(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	c;

	c = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (c != len)
	{
		str[c] = s[start];
		c++;
		start++;
	}
	str[c] = '\0';
	ft_strdel((char **)&s);
	return (str);
}

static char	*ft_strjoinf(char const *s1, char const *s2, int f)
{
	char	*join;
	int		i;
	int		j;

	if (!s1 || !s2 || 
			!(join = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		join[i] = s1[i];
	while (s2[++j])
		join[i + j] = s2[j];
	if (f == 1 || f == 3)
		ft_strdel((char **)(&s1));
	if (f == 2 || f == 3)
		ft_strdel((char **)(&s2));
	return (join);
}

static t_buff		*crea_lst(t_buff **buff, int fd, int chk)
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

static t_buff		*check_buff(t_buff **cpy, int fd)
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

int			read_file(t_buff *cpy, char **line, int fd)
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

int			get_next_line(const int fd, char **line)
{
	static t_buff	*buff;
	t_buff		*cpy;

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
