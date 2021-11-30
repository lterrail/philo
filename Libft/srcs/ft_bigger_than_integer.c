/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigger_than_integer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:22:31 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/25 20:23:41 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_bigger_than_integer(char *p, int i)
{
	int		j;

	j = 0;
	if (i > 10)
		return (0);
	else if (i == 10)
	{
		if (p[0] == '-')
			j++;
		while (p[j] >= '0' && p[j] <= '9')
			j++;
	}
	if ((p[0] == '-' && j != i + 1) || (p[0] != '-' && j != i))
		return (0);
	return (1);
}
