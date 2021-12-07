/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:06:40 by cnicolas          #+#    #+#             */
/*   Updated: 2021/11/25 14:06:41 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	int		j;
	char	*pt;

	i = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		if (s1[i] == s2[0])
		{
			pt = (char *)s1 + i;
			j = 0;
			while (s1[i + j] == s2[j] && i + j < len)
			{
				if (s2[j + 1] == '\0')
					return (pt);
				j++;
			}
			pt = 0;
		}
		i++;
	}
	return (NULL);
}
