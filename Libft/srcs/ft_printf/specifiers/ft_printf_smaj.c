/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_smaj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 02:44:43 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/19 16:26:59 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wstrlen(t_printf *pf, int *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if ((*str >= 0xD800 && *str <= 0xdfff) || (*str > 255 &&
		MB_CUR_MAX == 1) || *str > 0x10FFFF)
			return (pf->printed = -1);
		if (*str > 0xFFFF)
			i += 4;
		else if (*str > 0x7FF)
			i += 3;
		else if ((*str > 0x7F && MB_CUR_MAX != 1) || *str > 255)
			i += 2;
		else
			i += 1;
		str++;
	}
	return (i);
}

static int	ft_wstrlen2(t_printf *pf, int *str)
{
	int i;

	i = 0;
	while (*str && i <= pf->precision)
	{
		if (i == pf->precision)
			return (i);
		if ((*str >= 0xD800 && *str <= 0xdfff) || (*str > 255 &&
		MB_CUR_MAX == 1) || *str > 0x10FFFF)
			return (pf->printed = -1);
		if (*str > 0xFFFF)
			i += (i + 4 <= pf->precision ? 4 : 0);
		else if (*str > 0x7FF)
			i += (i + 3 <= pf->precision ? 3 : 0);
		else if ((*str > 0x7F && MB_CUR_MAX != 1) || *str > 255)
			i += (i + 2 <= pf->precision ? 2 : 0);
		else
			i += (i + 1 <= pf->precision ? 1 : 0);
		str++;
	}
	return (i);
}

static void	ft_pputnwstr(int *str, int len)
{
	int	i;

	i = 0;
	while (*str && i < len)
	{
		if (*str > 0xFFFF)
			i += 4;
		else if (*str > 0x7FF)
			i += 3;
		else if ((*str > 0x7F && MB_CUR_MAX != 1) || *str > 255)
			i += 2;
		else
			i++;
		if (i <= len)
			ft_pputwchar(*str++);
	}
}

int			ft_printf_smaj(t_printf *pf)
{
	int				len;
	int				*str;

	str = va_arg(pf->ap, int *);
	if (str == NULL)
		str = L"(null)";
	if (pf->precision == 0 && (len = ft_wstrlen(pf, str)) == -1)
		return (EXIT_ERROR);
	if (pf->precision > 0 && (len = ft_wstrlen2(pf, str)) == -1)
		return (EXIT_ERROR);
	if (pf->precision == -1)
		len = 0;
	pf->printed += len;
	if (pf->moins == 0 && pf->width > 0)
		ft_pputnchar(pf, ' ', pf->width - len);
	if (pf->moins == 0 && pf->zero > 0)
		ft_pputnchar(pf, '0', pf->zero - len);
	ft_pputnwstr(str, len);
	if (pf->moins > 0 && pf->width > 0)
		ft_pputnchar(pf, ' ', pf->width - len);
	if (pf->moins > 0 && pf->zero > 0)
		ft_pputnchar(pf, '0', pf->zero - len);
	return (EXIT_SUCCESS);
}
