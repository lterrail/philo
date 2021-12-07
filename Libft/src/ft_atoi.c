/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:00:04 by cnicolas          #+#    #+#             */
/*   Updated: 2021/11/25 14:00:07 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				n;
	long long int	temp;

	i = 0;
	n = 1;
	temp = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		n = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = temp * 10 + (str[i] - '0');
		i++;
		if (temp > 2147483647 && n > 0)
			return (-1);
		else if (temp > 2147483648 && n < 0)
			return (0);
	}
	temp = temp * n;
	return ((int)temp);
}
