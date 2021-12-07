/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:03:51 by cnicolas          #+#    #+#             */
/*   Updated: 2021/11/25 14:03:52 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ddst;
	unsigned char	*ssrc;
	unsigned int	i;

	ddst = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ddst[i] = ssrc[i];
		if (ssrc[i] == (unsigned char)c)
			return ((void *)&ddst[i + 1]);
		i++;
	}
	return (NULL);
}
