/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:21:26 by cnicolas          #+#    #+#             */
/*   Updated: 2021/12/10 16:11:50 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_table(t_table *table)
{
    int i;
    i = -1;

    if (!(table->philo = (t_philo *)malloc(sizeof(t_philo) * table->nb_philo)))
		return (ERROR_MALLOC);
	if (!(table->threads = (pthread_t *)malloc(sizeof(pthread_t) * table->nb_philo)))
		return (ERROR_MALLOC);
    table->dead = 0;
    table->begin_time = get_time();
    while (++i < table->nb_philo)
    {
        table->philo[i].id = i;
        table->philo[i].last_meal = table->begin_time;
        if (!(table->philo[i].fork_left = malloc(sizeof(pthread_mutex_t))))
            return (ERROR_MALLOC);
		pthread_mutex_init(table->philo[i].fork_left, NULL);
	}
	i = -1;
    while (++i < table->nb_philo)
    {
        if (i != 0)
            table->philo[i].fork_right = table->philo[i - 1].fork_left;
        else
            table->philo[i].fork_right = table->philo[table->nb_philo - 1].fork_left;
    }
    i = -1;
    while (++i < table->nb_philo)
	{
        table->philo[i].table = table;
	}
    return (SUCCESS);
}