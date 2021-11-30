/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:20:18 by lterrail          #+#    #+#             */
/*   Updated: 2018/04/12 11:51:08 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
		i++;
	if (i == 0 || i == 1)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

void			ft_putnbr_base(int nbr, char *base)
{
	int		i;
	long	b;

	b = nbr;
	i = 0;
	if (ft_check_base(base) == 1)
	{
		while (base[i])
			i++;
		if (b < 0)
		{
			ft_putchar('-');
			b *= -1;
		}
		if (b < i)
		{
			ft_putchar(base[b]);
		}
		else if (b >= i)
		{
			ft_putnbr_base(b / i, base);
			ft_putnbr_base(b % i, base);
		}
	}
}
