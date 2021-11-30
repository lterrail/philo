/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:17:56 by lterrail          #+#    #+#             */
/*   Updated: 2018/04/11 16:51:15 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tab;

	if (!(tab = malloc(sizeof(void) * size)))
		return (NULL);
	if (tab)
		ft_bzero(tab, size);
	return (tab);
}
