/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pourcent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 22:21:17 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/19 16:26:53 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf_pourcent(t_printf *pf)
{
	if (pf->moins == 0 && pf->width > 0)
		ft_pputnchar(pf, ' ', pf->width - 1);
	if (pf->moins == 0 && pf->zero > 0)
		ft_pputnchar(pf, '0', pf->zero - 1);
	pf->printed += write(1, "%", 1);
	if (pf->moins > 0 && pf->zero > 0)
		ft_pputnchar(pf, ' ', pf->zero - 1);
	if (pf->moins > 0 && pf->width > 0)
		ft_pputnchar(pf, ' ', pf->width - 1);
	return (EXIT_SUCCESS);
}
