/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghazari <mghazari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 09:38:07 by mghazari          #+#    #+#             */
/*   Updated: 2017/04/18 15:09:08 by mghazari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_buff
{
	int				fd;
	int				ind;
	char			*buff;
	struct s_buff	*next;
}				t_buff;

int				get_next_line(const int fd, char **line);
int				read_file(t_buff *cpy, char **line, int fd);

#endif
