/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghazari <mghazari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 21:46:59 by mghazari          #+#    #+#             */
/*   Updated: 2017/04/18 15:01:50 by mghazari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (((*alst)->next))
		ft_lstdel(&((*alst)->next), del);
	ft_lstdelone(alst, del);
	free(*alst);
	*alst = NULL;
}
