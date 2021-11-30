/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 19:17:25 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/19 16:27:11 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_flags(t_printf *pf)
{
	if (pf->format[pf->i] == '#')
	{
		pf->hastag = TRUE;
		pf->i++;
	}
	if (pf->format[pf->i] == '+')
	{
		pf->plus = TRUE;
		pf->i++;
	}
	if (pf->format[pf->i] == '0' && pf->i++ &&
	(pf->zero = ft_atoi_i(pf->format, pf)))
		pf->zero < 0 ? pf->zero *= -1 : pf->zero;
	if (pf->format[pf->i] == ' ')
	{
		pf->white_space = TRUE;
		pf->i++;
	}
	if (pf->format[pf->i] == '-')
	{
		pf->moins = TRUE;
		pf->i++;
	}
}

void	get_width(t_printf *pf)
{
	if (pf->format[pf->i] == '*')
	{
		pf->width = va_arg(pf->ap, int);
		pf->i++;
		if (pf->width < 0)
		{
			pf->width *= -1;
			pf->moins = TRUE;
		}
	}
	else if (pf->format[pf->i] > '0' && pf->format[pf->i] <= '9')
		pf->width = ft_atoi_i(pf->format, pf);
}

void	get_precision(t_printf *pf)
{
	if (pf->format[pf->i] == '.')
	{
		pf->i++;
		if (pf->format[pf->i] == '0' && pf->format[pf->i + 1] > '9')
		{
			pf->precision = -1;
			pf->i++;
		}
		else if (pf->format[pf->i] == '*')
		{
			pf->precision = va_arg(pf->ap, int);
			pf->i++;
			if (pf->precision == 0)
				pf->precision = -1;
		}
		else if ((pf->precision = ft_atoi_i(pf->format, pf)) == 0)
			pf->precision = -1;
	}
}

void	get_modificateur(t_printf *pf)
{
	if (pf->format[pf->i] == 'h' && pf->format[pf->i + 1] == 'h')
	{
		pf->conv = 2;
		pf->i = pf->i + 2;
	}
	if (pf->format[pf->i] == 'h')
	{
		pf->conv = 1;
		pf->i++;
	}
	if (pf->format[pf->i] == 'j')
	{
		pf->conv = 3;
		pf->i++;
	}
	if (pf->format[pf->i] == 'z')
	{
		pf->conv = 4;
		pf->i++;
	}
}

void	get_modificateur_suite(t_printf *pf)
{
	if (pf->format[pf->i] == 'l' && pf->format[pf->i + 1] == 'l')
	{
		pf->conv = 6;
		pf->i = pf->i + 2;
	}
	if (pf->format[pf->i] == 'l')
	{
		pf->conv = 5;
		pf->i++;
	}
}
