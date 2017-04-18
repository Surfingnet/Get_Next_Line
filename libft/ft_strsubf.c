/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghazari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:43:54 by mghazari          #+#    #+#             */
/*   Updated: 2017/04/18 14:45:31 by mghazari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubf(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	c;

	c = 0;
	if (!s)
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
