/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:33:16 by lterrail          #+#    #+#             */
/*   Updated: 2018/04/11 17:30:25 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		new[i] = f(i, s[i]);
		i++;
	}
	return (new);
}
