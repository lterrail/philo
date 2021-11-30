/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 20:36:06 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/19 16:26:50 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		solve_printf_o(t_printf *pf, int len)
{
	if (pf->plus > 0)
		pf->plus = 0;
	if (pf->white_space > 0)
		pf->white_space = 0;
	if ((pf->moins > 0 && pf->zero > 0) || (pf->zero > 0 &&
	((pf->precision > 1 && pf->hastag > 0) || (pf->precision > 0 &&
	pf->hastag == 0))))
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

int				ft_printf_solve_o(t_printf *pf, char *base, char *prefix)
{
	long long	save;
	int			len;
	char		*c_save;

	save = solve_modificateurs(pf, UNSIGNED);
	if (ft_preci_save_zero(pf, save) == 0)
		return (0);
	if (pf->precision == -1)
		pf->precision = 1;
	if (!(c_save = ft_llong_itoa(save, base)))
		return (0);
	len = ft_strlen(c_save);
	if (pf->hastag > 0 && (c_save[0] != prefix[0]))
		len += 1;
	else
		pf->hastag = 0;
	solve_printf_o(pf, len);
	ft_print(pf, c_save, prefix);
	free(c_save);
	return (EXIT_SUCCESS);
}

int				ft_printf_o(t_printf *pf)
{
	return (ft_printf_solve_o(pf, "01234567", "0"));
}

int				ft_printf_omaj(t_printf *pf)
{
	if (pf->conv < 5)
		pf->conv = 5;
	return (ft_printf_solve_o(pf, "01234567", "0"));
}
