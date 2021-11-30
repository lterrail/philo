/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:36:13 by lterrail          #+#    #+#             */
/*   Updated: 2018/06/27 16:42:18 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_char(char *str, char c)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			nb++;
		i++;
	}
	return (nb);
}
