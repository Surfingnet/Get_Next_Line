/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_Next_Line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghazari <mghazari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 09:40:20 by mghazari          #+#    #+#             */
/*   Updated: 2017/02/08 23:07:36 by mghazari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int check_fd(t_list **file)

static int cpy_line(char *buf, char* dest)
{
	while
}

int		get_next_line(const int fd, char **line)
{
	int	ret;
	int	i;
	int	stop;
	char	buf[BUFF_SIZE + 1];

	stop = 0;
	i = 0;
	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) && !stop)
	{

	}
	return (1);
}
