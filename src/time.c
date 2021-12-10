/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:12:39 by cnicolas          #+#    #+#             */
/*   Updated: 2021/12/10 15:13:56 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	get_time(void)
{
    struct timeval  current_time;

    gettimeofday(&current_time, NULL);
	return (current_time.tv_sec*1000 + current_time.tv_usec/1000);
}

long long int	elapsed_time(t_philo *philo)
{
	long long int  end_time;

	end_time = get_time();
	return (end_time - philo->table->begin_time);
}