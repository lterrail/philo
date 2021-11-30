/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:33:09 by lterrail          #+#    #+#             */
/*   Updated: 2018/04/11 17:30:13 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		length;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	length = ft_strlen(s);
	if (!(new = malloc(sizeof(char) * length + 1)))
		return (NULL);
	new[length] = '\0';
	while (s[i])
	{
		new[i] = f(s[i]);
		i++;
	}
	return (new);
}
