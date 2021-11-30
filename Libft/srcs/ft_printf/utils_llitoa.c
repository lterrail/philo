/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_llitoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:41:08 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/19 16:27:30 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_itoa(unsigned long long nb, size_t base_len)
{
	int	size;

	size = 0;
	if (!nb)
		return (1);
	while (nb)
	{
		size++;
		nb = nb / base_len;
	}
	return (size);
}

char		*ft_llong_itoa(unsigned long long nb, char *base)
{
	char	*new;
	size_t	base_len;
	size_t	len;
	size_t	i;

	base_len = ft_strlen(base);
	len = ft_strlen_itoa(nb, base_len);
	if (!(new = malloc(len + 1)))
		return (NULL);
	i = 0;
	new[len] = '\0';
	while (i < len)
	{
		new[len - 1] = base[nb % base_len];
		nb = nb / base_len;
		len--;
	}
	return (new);
}
