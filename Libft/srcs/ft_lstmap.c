/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:50:20 by lterrail          #+#    #+#             */
/*   Updated: 2018/04/10 18:00:37 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*tmp;

	if (!(begin = f(lst)))
		return (NULL);
	tmp = begin;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp->next = f(lst)))
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (begin);
}
