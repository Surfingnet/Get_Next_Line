/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghazari <mghazari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:29:56 by mghazari          #+#    #+#             */
/*   Updated: 2017/04/18 15:07:36 by mghazari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int		fd1;
	int		fd2;
	char	*str1;
	char	*str2;

	if (argc != 3)
		return (0);
	fd1 = (open(argv[1], O_RDONLY));
	fd2 = (open(argv[2], O_RDONLY));
	get_next_line(fd1, &str1);
	ft_putendl(str1);
	get_next_line(fd2, &str2);
	ft_putendl(str2);
	get_next_line(fd1, &str1);
	ft_putendl(str1);
	get_next_line(fd2, &str2);
	ft_putendl(str2);
	get_next_line(fd2, &str2);
	ft_putendl(str2);
	get_next_line(fd1, &str1);
	ft_putendl(str1);
	get_next_line(fd1, &str1);
	ft_putendl(str1);
	return (0);
}
