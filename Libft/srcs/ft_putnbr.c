/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:25:09 by lterrail          #+#    #+#             */
/*   Updated: 2018/04/11 17:03:43 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	nombre;

	nombre = n;
	if (nombre < 0)
	{
		ft_putchar('-');
		nombre = -nombre;
	}
	if (nombre >= 0 && nombre <= 9)
		ft_putchar(nombre + '0');
	if (nombre > 9)
	{
		ft_putnbr(nombre / 10);
		ft_putnbr(nombre % 10);
	}
}
