/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:53:33 by lterrail          #+#    #+#             */
/*   Updated: 2018/04/10 14:28:16 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen(int n)
{
	int		i;
	long	nombre;

	nombre = n;
	i = 0;
	if (!nombre)
		return (1);
	if (nombre < 0)
	{
		nombre = -nombre;
		i++;
	}
	while (nombre > 0)
	{
		nombre = nombre / 10;
		i++;
	}
	return (i);
}

static int		ft_negativ(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_itoa(int n)
{
	char		*str;
	size_t		nombre;
	size_t		length;
	size_t		i;

	nombre = n;
	i = 0;
	length = ft_intlen(nombre);
	if (!(str = malloc(sizeof(char) * length + 1)))
		return (0);
	if (n < 0)
	{
		str[i++] = '-';
		nombre = -nombre;
	}
	str[length] = '\0';
	while (i < length)
	{
		str[length - 1] = (nombre % 10) + '0';
		nombre = nombre / 10;
		length--;
	}
	if (ft_negativ(nombre))
		str[0] = '-';
	return (str);
}
