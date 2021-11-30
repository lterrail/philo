/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 13:03:46 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/19 16:27:27 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_specifiers(t_printf *pf)
{
	if (pf->format[pf->i] == 'd')
		return (ft_printf_d(pf));
	else if (pf->format[pf->i] == 's' && pf->conv == 5)
		return (ft_printf_smaj(pf));
	else if (pf->format[pf->i] == 's')
		return (ft_printf_s(pf));
	else if (pf->format[pf->i] == 'i')
		return (ft_printf_d(pf));
	else if (pf->format[pf->i] == 'D')
		return (ft_printf_ld(pf));
	else if (pf->format[pf->i] == 'c' && pf->conv == 5)
		return (ft_printf_cmaj(pf));
	else if (pf->format[pf->i] == 'c')
		return (ft_printf_c(pf));
	else if (pf->format[pf->i] == 'x')
		return (ft_printf_xmin(pf));
	else if (pf->format[pf->i] == 'X')
		return (ft_printf_xmaj(pf));
	else if (pf->format[pf->i] == 'p')
		return (ft_printf_p(pf));
	return (get_specifiers_suite(pf));
}

int		get_specifiers_suite(t_printf *pf)
{
	if (pf->format[pf->i] == '%')
		return (ft_printf_pourcent(pf));
	else if (pf->format[pf->i] == 'u')
		return (ft_printf_u(pf));
	else if (pf->format[pf->i] == 'U')
		return (ft_printf_umaj(pf));
	else if (pf->format[pf->i] == 'o')
		return (ft_printf_o(pf));
	else if (pf->format[pf->i] == 'O')
		return (ft_printf_omaj(pf));
	else if (pf->format[pf->i] == 'C')
		return (ft_printf_cmaj(pf));
	else if (pf->format[pf->i] == 'S')
		return (ft_printf_smaj(pf));
	else
		return (NO_SPECIFIER_ERR);
	return (EXIT_SUCCESS);
}
