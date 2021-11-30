/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:23:49 by lterrail          #+#    #+#             */
/*   Updated: 2018/04/11 17:00:22 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tab;
	size_t			i;

	i = 0;
	tab = (unsigned char *)b;
	while (i < len)
	{
		tab[i] = c;
		i++;
	}
	return (b);
}
