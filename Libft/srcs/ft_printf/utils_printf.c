/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:19:05 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/19 16:27:33 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_pputstrmaj(t_printf *pf, char *c_save)
{
	int	i;

	i = 0;
	while (c_save[i])
	{
		if (c_save[i] >= 'a' && c_save[i] <= 'z')
		{
			write(1, &c_save[i] - 32, 1);
			pf->printed++;
			i++;
		}
		else
		{
			write(1, &c_save[i], 1);
			pf->printed++;
			i++;
		}
	}
}

int			ft_preci_save_zero(t_printf *pf, long long save)
{
	if (pf->precision == -1 && save == 0)
	{
		if (pf->plus > 0)
			pf->printed += write(1, &pf->sign, 1);
		if (pf->white_space > 0)
			pf->printed += write(1, " ", 1);
		if (pf->width > 0)
			ft_pputnchar(pf, ' ', pf->width);
		if (pf->format[pf->i] == 'p')
			ft_pputstr(pf, "0x");
		if (pf->hastag > 0 && (pf->format[pf->i] == 'o' ||
		pf->format[pf->i] == 'O') && save == 0)
			pf->printed += write(1, "0", 1);
		return (0);
	}
	return (1);
}

int			ft_atoi_i(const char *str, t_printf *pf)
{
	int n;
	int neg;

	neg = 1;
	n = 0;
	while (str[pf->i] == ' ')
	{
		pf->white_space = TRUE;
		pf->i++;
	}
	if (str[pf->i] == '+')
	{
		pf->plus = TRUE;
		pf->i++;
	}
	else if (str[pf->i] == '-')
	{
		pf->moins = TRUE;
		neg = -1;
		pf->i++;
	}
	while (str[pf->i] && (str[pf->i] >= '0' && str[pf->i] <= '9'))
		n = n * 10 + (str[pf->i++] - '0');
	return (n * neg);
}
