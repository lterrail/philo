/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:36:16 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/23 19:12:34 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_split2(const char *str, char **tab, char c, int size)
{
	int	i_tab;
	int	n;
	int	i;

	i = 0;
	i_tab = 0;
	while (str[i] && i_tab < size)
	{
		while (str[i] && c == str[i])
			i++;
		n = 0;
		while (str[i + n] && c != str[i + n])
			n++;
		if (!(tab[i_tab] = malloc(n + 1)))
			return (0);
		n = 0;
		while (str[i] && c != str[i])
		{
			tab[i_tab][n] = str[i++];
			n++;
		}
		tab[i_tab++][n] = '\0';
	}
	tab[size] = NULL;
	return (1);
}

char			**ft_strsplit(const char *str, char c)
{
	char	**tab;
	int		tab_size;
	int		i;

	i = 0;
	tab_size = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		while (str[i] && c == str[i])
			i++;
		if (str[i])
			tab_size++;
		while (str[i] && c != str[i])
			i++;
	}
	if (!(tab = malloc(sizeof(char *) * (tab_size + 1))))
		return (NULL);
	if (!ft_split2(str, tab, c, tab_size))
		return (NULL);
	return (tab);
}
