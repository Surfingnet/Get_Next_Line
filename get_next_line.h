/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghazari <mghazari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 09:38:07 by mghazari          #+#    #+#             */
/*   Updated: 2017/04/15 13:06:46 by mghazari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# define BUFF_SIZE 8
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_buff
{
	int		fd;
	int		ind;
	char		*buff;
	struct s_buff	*next;
}			t_buff;

int	get_next_line(const int fd, char **line);
int	read_file(t_buff *cpy, char **line, int fd);

#endif
