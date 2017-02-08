/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghazari <mghazari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:29:56 by mghazari          #+#    #+#             */
/*   Updated: 2017/01/29 18:36:58 by mghazari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int	fd;
	int	strsize;
	char*	str;

	if (argc != 2)
		return (0);

	strsize = 200;

	while (!(str = (char*)malloc(sizeof(char) * strsize + 1)))
		continue;
	ft_putendl("malloc ok");
	fd = (open(argv[1], O_RDONLY));
	get_next_line(fd, &str);
	ft_putendl(str);
	ft_strdel(&str);
	ft_putendl("freed");
	return (0);
}
