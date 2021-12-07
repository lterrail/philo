/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:04:46 by cnicolas          #+#    #+#             */
/*   Updated: 2021/11/25 14:04:47 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*d;
	unsigned int	i;

	d = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		d[i] = (unsigned char)c;
		i++;
	}
	b = (void *)d;
	return (b);
}
