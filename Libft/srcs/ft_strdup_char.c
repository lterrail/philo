/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:23:48 by lterrail          #+#    #+#             */
/*   Updated: 2018/06/27 16:27:56 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup_char(const char *str, char c)
{
	int		i_str;
	int		j;
	char	*cpy;

	i_str = 0;
	j = 0;
	while (str[i_str] != c)
		i_str++;
	if (!(cpy = malloc(sizeof(char) * i_str + 1)))
		return (0);
	while (str[j] != c)
	{
		cpy[j] = str[j];
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}
