/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:00:24 by cnicolas          #+#    #+#             */
/*   Updated: 2021/11/25 14:00:27 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*pt;

	pt = (void *)malloc(nitems * size);
	if (!pt)
		return (NULL);
	ft_bzero(pt, nitems * size);
	return (pt);
}
