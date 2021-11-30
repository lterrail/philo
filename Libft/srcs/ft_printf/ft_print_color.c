/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:55:48 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/19 16:47:29 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_tab_color2(t_printf *pf, int *ret)
{
	if (ft_strncmp("light gray", pf->color, ft_strlen("light gray")) == 0)
		my_putstr("\e[90m");
	else if (ft_strncmp("light red", pf->color, ft_strlen("light red"))
	== 0)
		my_putstr("\e[91m");
	else if (ft_strncmp("light green", pf->color, ft_strlen("light green"))
	== 0)
		my_putstr("\e[92m");
	else if (ft_strncmp("light yellow", pf->color, ft_strlen("light yellow"))
	== 0)
		my_putstr("\e[93m");
	else if (ft_strncmp("light blue", pf->color, ft_strlen("light blue")) == 0)
		my_putstr("\e[94m");
	else if (ft_strncmp("light magenta", pf->color, ft_strlen("light magenta"))
	== 0)
		my_putstr("\e[95m");
	else if (ft_strncmp("light cyan", pf->color, ft_strlen("light cyan")) == 0)
		my_putstr("\e[96m");
	else if (ft_strncmp("white", pf->color, ft_strlen("white")) == 0)
		my_putstr("\e[97m");
	else
		*ret = COLOR_ERR;
}

static void	ft_tab_color(t_printf *pf, int *ret)
{
	if (ft_strncmp("eoc", pf->color, ft_strlen("eoc")) == 0)
		my_putstr("\e[39m");
	else if (ft_strncmp("black", pf->color, ft_strlen("black")) == 0)
		my_putstr("\e[30m");
	else if (ft_strncmp("red", pf->color, ft_strlen("red")) == 0)
		my_putstr("\e[31m");
	else if (ft_strncmp("green", pf->color, ft_strlen("green")) == 0)
		my_putstr("\e[32m");
	else if (ft_strncmp("yellow", pf->color, ft_strlen("yellow")) == 0)
		my_putstr("\e[33m");
	else if (ft_strncmp("blue", pf->color, ft_strlen("blue")) == 0)
		my_putstr("\e[34m");
	else if (ft_strncmp("magenta", pf->color, ft_strlen("magenta")) == 0)
		my_putstr("\e[35m");
	else if (ft_strncmp("cyan", pf->color, ft_strlen("cyan")) == 0)
		my_putstr("\e[36m");
	else
		ft_tab_color2(pf, ret);
}

int			get_color(t_printf *pf)
{
	int		i_form;
	int		ret;

	ret = 0;
	i_form = 1;
	while (pf->format[pf->i + i_form] != '}')
		i_form++;
	if (i_form - 1 == 1 && pf->format[i_form - 1] == '*')
	{
		pf->color = va_arg(pf->ap, char *);
		ft_tab_color(pf, &ret);
		if (ret != COLOR_ERR)
			ret = 2;
	}
	else
	{
		pf->color = (char *)pf->format + (pf->i + 1);
		ft_tab_color(pf, &ret);
		if (ret != COLOR_ERR)
			ret = i_form;
	}
	return (ret);
}
