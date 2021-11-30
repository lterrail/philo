/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buble_sort_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:21:54 by lterrail          #+#    #+#             */
/*   Updated: 2018/06/27 18:23:51 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_buble_sort_tab(char **tab, int nb)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < nb)
	{
		j = 0;
		while (j < nb - 1)
		{
			if (ft_strlen(tab[j]) > ft_strlen(tab[j + 1]))
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}
