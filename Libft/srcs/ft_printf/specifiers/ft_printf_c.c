/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:49:03 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/19 16:47:47 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_printf_c(t_printf *pf)
{
	char	c[2];

	c[0] = (char)va_arg(pf->ap, int);
	c[1] = '\0';
	if (pf->zero > 0)
	{
		pf->zero = pf->zero - 1;
		ft_pputnchar(pf, '0', pf->zero);
	}
	if (pf->moins == 0 && pf->width > 0)
		ft_pputnchar(pf, ' ', pf->width - 1);
	pf->printed += write(1, &c[0], 1);
	if (pf->moins > 0 && pf->width > 0)
		ft_pputnchar(pf, ' ', pf->width - 1);
	return (EXIT_SUCCESS);
}

static int	ft_wchrlen(unsigned int chr, int len)
{
	if (chr > 0xFFFF)
		len = 4;
	else if (chr > 0x7FF)
		len = 3;
	else if ((chr > 0x7F && MB_CUR_MAX != 1) || chr > 255)
		len = 2;
	else
		len = 1;
	return (len);
}

void		ft_pputwchar(unsigned int chr)
{
	if (chr > 0xFFFF)
	{
		ft_putchar((chr >> 18) + 0xF0);
		ft_putchar(((chr >> 12) & 0x3F) + 0x80);
		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr > 0x7FF)
	{
		ft_putchar((chr >> 12) + 0xE0);
		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar((chr & 0x3F) + 0x80);
	}
	else if ((chr > 0x7F && MB_CUR_MAX != 1) || chr > 255)
	{
		ft_putchar((chr >> 6) + 0xC0);
		ft_putchar((chr & 0x3F) + 0x80);
	}
	else
		ft_putchar(chr);
}

int			ft_printf_cmaj(t_printf *pf)
{
	unsigned int	chr;
	int				len;

	len = 0;
	chr = va_arg(pf->ap, unsigned int);
	len = ft_wchrlen(chr, len);
	if ((chr >= 0xd800 && chr <= 0xdfff) ||
		(chr > 255 && MB_CUR_MAX == 1) || chr > 0x10FFFF)
		return (pf->printed = -1);
	if (pf->moins == 0 && pf->width > 0)
		ft_pputnchar(pf, ' ', pf->width - len);
	ft_pputwchar(chr);
	if (pf->moins > 0 && pf->width > 0)
		ft_pputnchar(pf, ' ', pf->width - len);
	pf->printed += len;
	return (EXIT_SUCCESS);
}
