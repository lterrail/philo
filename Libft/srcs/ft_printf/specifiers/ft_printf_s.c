/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 13:05:25 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/19 16:26:56 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_print_s(t_printf *pf, char *save, int len)
{
	if (pf->moins == 0 && pf->zero > 0)
		ft_pputnchar(pf, '0', pf->zero - len);
	if (pf->moins == 0 && pf->width > 0)
		ft_pputnchar(pf, ' ', pf->width);
	if (save && pf->precision > 0)
		ft_pputnstr(pf, save, len);
	else if (!save && pf->precision > 0)
		ft_pputnstr(pf, "(null)", len);
	else if (save && pf->precision != -1)
		ft_pputstr(pf, save);
	else if (!save && pf->precision != -1)
		ft_pputstr(pf, "(null)");
	if (pf->moins == 1 && pf->width > 0)
		ft_pputnchar(pf, ' ', pf->width);
	if (pf->moins == 1 && pf->zero > 0)
		ft_pputnchar(pf, ' ', pf->zero - len);
}

int				ft_printf_s(t_printf *pf)
{
	char	*save;
	int		len;

	len = 0;
	save = va_arg(pf->ap, char *);
	if (save)
		len = ft_strlen(save);
	else if (pf->precision != -1)
		len = ft_strlen("(null)");
	if (pf->precision > 0 && pf->precision <= len)
		len = pf->precision;
	if (pf->precision > len)
		pf->precision = len;
	if (pf->width > 0 && (pf->width > pf->precision))
	{
		if (pf->precision > 0)
			pf->width = pf->width - pf->precision;
		else if (pf->precision == 0)
			pf->width = pf->width - len;
	}
	else
		pf->width = 0;
	ft_print_s(pf, save, len);
	return (EXIT_SUCCESS);
}
