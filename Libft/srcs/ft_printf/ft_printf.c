/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:48:32 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/19 16:27:24 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_printf_init(t_printf *pf, const char *format)
{
	pf->format = format;
	pf->i = 0;
	pf->color = NULL;
	pf->hastag = FALSE;
	pf->pourcent = FALSE;
	pf->plus = FALSE;
	pf->moins = FALSE;
	pf->zero = FALSE;
	pf->white_space = FALSE;
	pf->precision = FALSE;
	pf->width = FALSE;
	pf->conv = FALSE;
	pf->sign = '+';
	pf->printed = 0;
}

static void		ft_printf_restart(t_printf *pf)
{
	pf->hastag = FALSE;
	pf->pourcent = FALSE;
	pf->plus = FALSE;
	pf->moins = FALSE;
	pf->zero = FALSE;
	pf->white_space = FALSE;
	pf->precision = FALSE;
	pf->width = FALSE;
	pf->conv = FALSE;
	pf->sign = '+';
}

static void		get_everything(t_printf *pf)
{
	get_flags(pf);
	get_width(pf);
	get_precision(pf);
	get_modificateur(pf);
	get_modificateur_suite(pf);
}

static int		ft_process(t_printf *pf)
{
	int ret;
	int i_check;

	ret = 0;
	pf->i++;
	i_check = pf->i;
	get_everything(pf);
	while (pf->i > i_check)
	{
		i_check = pf->i;
		get_everything(pf);
	}
	ret = get_specifiers(pf);
	if (ret == NO_SPECIFIER_ERR)
		ret = ft_print_nospecifier(pf);
	ft_printf_restart(pf);
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	t_printf	pf;
	int			ret;

	ret = 0;
	va_start(pf.ap, format);
	ft_printf_init(&pf, format);
	if (pf.format[pf.i] == '%' && (ft_strlen(pf.format)) == 1)
		return (EXIT_SUCCESS);
	while (format[pf.i])
	{
		if (format[pf.i] == '{' && (ret = get_color(&pf)) != COLOR_ERR)
			pf.i += ret + 1;
		if (format[pf.i] == '%')
		{
			if ((ret = ft_process(&pf)) == EXIT_ERROR)
				return (pf.printed);
		}
		else if (ret == EXIT_ERROR)
			return (pf.printed);
		else
			pf.printed += write(1, &pf.format[pf.i], 1);
		pf.i++;
	}
	va_end(pf.ap);
	return (pf.printed);
}
