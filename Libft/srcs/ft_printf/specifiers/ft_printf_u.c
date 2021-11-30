/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 23:19:43 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/19 16:27:03 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_printf_u(t_printf *pf)
{
	if (pf->white_space > 0)
		pf->white_space = FALSE;
	if (pf->plus > 0)
		pf->plus = FALSE;
	return (ft_printf_solve_x(pf, "0123456789", "toto"));
}

int				ft_printf_umaj(t_printf *pf)
{
	if (pf->conv < 5)
		pf->conv = 5;
	return (ft_printf_solve_x(pf, "0123456789", "toto"));
}
