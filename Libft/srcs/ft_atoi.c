/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:19:24 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/25 20:34:25 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int n;
	int neg;

	neg = 0;
	n = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' ||
		*str == '\r' || *str == '\f')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg = 1;
		str++;
	}
	while (*str != '\0' && ft_isdigit(*str))
	{
		n = n * 10 + (*str++ - '0');
	}
	if (neg)
		return (-n);
	else
		return (n);
}
