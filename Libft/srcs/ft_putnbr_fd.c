/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:50:47 by lterrail          #+#    #+#             */
/*   Updated: 2018/04/07 13:34:39 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nombre;

	nombre = n;
	if (nombre < 0)
	{
		ft_putchar_fd('-', fd);
		nombre = -nombre;
	}
	if (nombre >= 0 && nombre <= 9)
		ft_putchar_fd(nombre + '0', fd);
	if (nombre > 9)
	{
		ft_putnbr_fd(nombre / 10, fd);
		ft_putnbr_fd(nombre % 10, fd);
	}
}
