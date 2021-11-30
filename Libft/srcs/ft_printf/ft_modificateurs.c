/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modificateurs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 22:52:18 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/19 16:27:14 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	solve_modificateurs_unsigned(t_printf *pf)
{
	long long	nbr;

	if (pf->conv == HH_CONV)
		nbr = (unsigned char)va_arg(pf->ap, unsigned int);
	else if (pf->conv == H_CONV)
		nbr = (unsigned short)va_arg(pf->ap, unsigned int);
	else if (pf->conv == LL_CONV || pf->conv == Z_CONV)
		nbr = va_arg(pf->ap, unsigned long long);
	else if (pf->conv == L_CONV || pf->conv == J_CONV)
		nbr = va_arg(pf->ap, unsigned long);
	else
		nbr = va_arg(pf->ap, unsigned int);
	return (nbr);
}

long long	solve_modificateurs(t_printf *pf, int sign)
{
	long long nbr;

	if (sign == UNSIGNED)
		return (solve_modificateurs_unsigned(pf));
	if (pf->conv == HH_CONV)
		nbr = (char)va_arg(pf->ap, int);
	else if (pf->conv == H_CONV)
		nbr = (short)va_arg(pf->ap, int);
	else if (pf->conv == LL_CONV || pf->conv == Z_CONV)
		nbr = va_arg(pf->ap, long long);
	else if (pf->conv == L_CONV || pf->conv == J_CONV)
		nbr = va_arg(pf->ap, long);
	else
		nbr = va_arg(pf->ap, int);
	return (nbr);
}
