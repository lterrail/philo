/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:37:28 by lterrail          #+#    #+#             */
/*   Updated: 2018/04/11 17:44:36 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;

	i = 0;
	if (ft_strcmp(little, "") == 0)
		return ((char*)big);
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j] || little[j] == '\0')
		{
			if (little[j] == '\0')
				return ((char*)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
