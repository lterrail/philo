/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:38:52 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/19 16:27:06 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		solve_printf_x(t_printf *pf, int len)
{
	if (pf->white_space > 0)
		pf->white_space = 0;
	if (pf->plus > 0)
		pf->plus = 0;
	if ((pf->moins > 0 && pf->zero > 0) || (pf->zero > 0 &&
	((pf->precision > 2 && pf->hastag > 0 && pf->format[pf->i] != 'p') ||
	(pf->precision > 0 && pf->hastag == 0 && pf->format[pf->i] != 'p'))))
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

int				ft_printf_solve_x(t_printf *pf, char *base, char *prefix)
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
		return (EXIT_SUCCESS);
	len = ft_strlen(c_save);
	if (pf->format[pf->i] == 'p' || (pf->hastag > 0 &&
	(c_save[0] != prefix[0] && c_save[1] != prefix[1])))
	{
		pf->precision += 2;
		len += 2;
	}
	else
		pf->hastag = 0;
	solve_printf_x(pf, len);
	ft_print(pf, c_save, prefix);
	free(c_save);
	return (EXIT_SUCCESS);
}

int				ft_printf_xmin(t_printf *pf)
{
	return (ft_printf_solve_x(pf, "0123456789abcdef", "0x"));
}

int				ft_printf_xmaj(t_printf *pf)
{
	return (ft_printf_solve_x(pf, "0123456789ABCDEF", "0X"));
}

int				ft_printf_p(t_printf *pf)
{
	if (pf->conv < 5)
		pf->conv = 5;
	return (ft_printf_solve_x(pf, "0123456789abcdef", "0x"));
}
