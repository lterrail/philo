/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:19:59 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/19 16:27:36 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pputnchar(t_printf *pf, char c, int n)
{
	while (n > 0)
	{
		pf->printed += write(1, &c, 1);
		n--;
	}
}

void	ft_pputstr(t_printf *pf, char *s)
{
	int len;

	len = ft_strlen(s);
	write(1, s, len);
	pf->printed += len;
}

void	ft_pputnstr(t_printf *pf, char *save, int len)
{
	write(1, save, len);
	pf->printed += len;
}

void	my_putstr(char *s)
{
	int len;

	len = ft_strlen(s);
	write(1, s, len);
}
