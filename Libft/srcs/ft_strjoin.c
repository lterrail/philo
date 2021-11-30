/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:31:56 by lterrail          #+#    #+#             */
/*   Updated: 2018/04/11 17:29:56 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i_s1;
	int		i_s2;

	i_s1 = 0;
	i_s2 = 0;
	if (!s1 && !s2)
		return (ft_strnew(0));
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	while (s1[i_s1])
	{
		str[i_s1] = s1[i_s1];
		i_s1++;
	}
	while (s2[i_s2])
		str[i_s1++] = s2[i_s2++];
	str[i_s1] = '\0';
	return (str);
}
