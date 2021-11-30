/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:09:40 by lterrail          #+#    #+#             */
/*   Updated: 2018/04/11 18:38:37 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(int n)
{
	int		i;
	long	nombre;

	nombre = n;
	i = 0;
	if (nombre == 0)
		return (1);
	while (nombre != 0)
	{
		nombre = nombre / 10;
		i++;
	}
	return (i);
}
