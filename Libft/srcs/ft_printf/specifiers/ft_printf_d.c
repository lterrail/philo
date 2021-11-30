/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:01:50 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/19 16:26:47 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		solve_printf_d(t_printf *pf, int len)
{
	if (pf->plus == 1)
		pf->white_space = FALSE;
	pf->hastag = FALSE;
	if ((pf->moins > 0 && pf->zero > 0) || (pf->zero > 0 && pf->precision > 0))
	{
		pf->width = pf->zero;
		pf->zero = 0;
	}
	if (pf->width > len && (pf->precision < len))
		pf->width = pf->width - len;
	else if (pf->width > len && ((pf->width - len) > (pf->precision - len)))
		pf->width = (pf->width + len) - (pf->precision + len);
	else
		pf->width = 0;
	if (pf->precision > len)
		pf->precision = pf->precision - len;
	else
		pf->precision = 0;
	if (pf->zero > len)
		pf->zero = pf->zero - len;
	else
		pf->zero = 0;
}

int				ft_printf_d(t_printf *pf)
{
	long long	save;
	int			len;
	char		*c_save;

	if ((save = solve_modificateurs(pf, SIGNED)) < 0)
		pf->sign = '-';
	if (ft_preci_save_zero(pf, save) == 0)
		return (EXIT_SUCCESS);
	if (pf->precision == -1)
		pf->precision = 1;
	if (!(c_save = ft_llong_itoa(save < 0 ? -save : save, "0123456789")))
		return (0);
	len = ft_strlen(c_save);
	if (save < 0 || (save >= 0 && (pf->white_space > 0 || pf->plus > 0)))
		len++;
	if (pf->precision > 0 && (save < 0 || (save >= 0 && (pf->white_space > 0 ||
		pf->plus > 0))))
		pf->precision++;
	solve_printf_d(pf, len);
	ft_print(pf, c_save, "oapwkodknka");
	free(c_save);
	return (EXIT_SUCCESS);
}

int				ft_printf_ld(t_printf *pf)
{
	if (pf->conv < 5)
		pf->conv = 5;
	ft_printf_d(pf);
	return (EXIT_SUCCESS);
}
