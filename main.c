/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghazari <mghazari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:29:56 by mghazari          #+#    #+#             */
/*   Updated: 2017/03/23 17:42:45 by mghazari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int		fd;
	char	*str;

	if (argc != 2)
		return (0);

	fd = (open(argv[1], O_RDONLY));
	get_next_line(fd, &str);
	ft_putendl("displaying");
	ft_putendl(str);
	//ft_strdel(&str);
	return (0);
}
