/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghazari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:45:57 by mghazari          #+#    #+#             */
/*   Updated: 2017/04/18 14:46:12 by mghazari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char const *s1, char const *s2, int f)
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
