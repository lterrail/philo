/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:34:53 by lterrail          #+#    #+#             */
/*   Updated: 2018/04/11 19:16:16 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] && n > 0)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
			n--;
		}
		if (n == 0)
			return (1);
		return (s1[i] != s2[i] ? 0 : 1);
	}
	return (0);
}
