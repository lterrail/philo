/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:49:00 by lterrail          #+#    #+#             */
/*   Updated: 2018/04/11 16:12:49 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *i_listchain;
	t_list *supr;

	i_listchain = *alst;
	while (i_listchain)
	{
		supr = i_listchain;
		i_listchain = i_listchain->next;
		ft_lstdelone(&supr, del);
	}
	*alst = NULL;
}
