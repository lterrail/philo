/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_resultat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:07:56 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/19 16:27:21 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print(t_printf *pf, char *c_save, char *prefix)
{
	if (pf->moins == 0)
	{
		if (pf->width > 0)
			ft_pputnchar(pf, ' ', pf->width);
		if (pf->sign == '-')
			pf->printed += write(1, "-", 1);
		else if (pf->sign == '+' && pf->white_space > 0)
			pf->printed += write(1, " ", 1);
		else if (pf->sign == '+' && pf->plus > 0)
			pf->printed += write(1, "+", 1);
		if (pf->format[pf->i] == 'p' || (pf->hastag > 0 && prefix[0] == '0'))
			ft_pputstr(pf, prefix);
		if (pf->zero > 0)
			ft_pputnchar(pf, '0', pf->zero);
		if (pf->precision > 0)
			ft_pputnchar(pf, '0', pf->precision);
		if (prefix[1] == 'X')
			ft_pputstrmaj(pf, c_save);
		else
			ft_pputstr(pf, c_save);
	}
	else
		ft_print_right(pf, c_save, prefix);
}

void		ft_print_right(t_printf *pf, char *c_save, char *prefix)
{
	if (pf->format[pf->i] == 'p' || (pf->hastag > 0 && prefix[0] == '0'))
		ft_pputstr(pf, prefix);
	if (pf->sign == '-')
		pf->printed += write(1, "-", 1);
	else if (pf->sign == '+' && pf->white_space > 0)
		pf->printed += write(1, " ", 1);
	else if (pf->sign == '+' && pf->plus > 0)
		pf->printed += write(1, "+", 1);
	if (pf->zero > 0)
		ft_pputnchar(pf, '0', pf->zero);
	if (pf->precision > 0)
		ft_pputnchar(pf, '0', pf->precision);
	ft_pputstr(pf, c_save);
	if (pf->width > 0)
		ft_pputnchar(pf, ' ', pf->width);
}

int			ft_print_nospecifier(t_printf *pf)
{
	if (pf->format[pf->i] == '\0')
		return (-1);
	if (pf->moins == 0)
	{
		if (pf->zero > 0)
			pf->zero -= 1;
		ft_pputnchar(pf, '0', pf->zero);
		if (pf->width > 0)
			pf->width -= 1;
		ft_pputnchar(pf, ' ', pf->width);
		pf->printed += write(1, &pf->format[pf->i], 1);
	}
	else if (pf->moins > 0)
	{
		pf->printed += write(1, &pf->format[pf->i], 1);
		if (pf->width > 0)
			pf->width -= 1;
		if (pf->zero > 0)
			pf->zero -= 1;
		ft_pputnchar(pf, '0', pf->zero);
		ft_pputnchar(pf, ' ', pf->width);
	}
	return (EXIT_SUCCESS);
}
