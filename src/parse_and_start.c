/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:27:25 by cnicolas          #+#    #+#             */
/*   Updated: 2021/12/10 16:51:40 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_parse_arg(char **av, int ac, t_table *table)
{
    if (ac < 5 || ac > 6)
        return (ERROR);
    table->nb_philo = ft_atoi(av[1]);
    table->time_to_die = ft_atoi(av[2]);
    table->time_to_eat = ft_atoi(av[3]);
    table->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
    {
        table->must_eat = ft_atoi(av[5]);
        if (table->must_eat <= 0)
            return (ERROR);
    }
    else
        table->must_eat = INT_MAX;
    if  (!table->nb_philo ||  !table->time_to_die ||  !table->time_to_eat ||  !table->time_to_sleep
            || table->nb_philo < 2 || table->time_to_die <= 0 || table->time_to_eat <= 0 || table->time_to_sleep <= 0)
        return (ERROR); // si ca  peut  fail ?
    if  (table->nb_philo < 1)
        return (ERROR_USAGE);
    return (SUCCESS);
}

void    *ft_start(void *void_philo)
{
	t_philo *philo;
    philo = (t_philo *)void_philo;
    philo->last_meal = 0;
    while (!philo->table->dead)
    {
        pthread_mutex_lock(philo->fork_right);
		ft_print_msg(philo, PRINT_FORK); /////
        	//printf("right fork & id %d\n",  philo->id);
        pthread_mutex_lock(philo->fork_left);
		ft_print_msg(philo, PRINT_FORK);
        	//printf("left fork  & id %d\n",  philo->id);
		ft_print_msg(philo, PRINT_EAT);
        philo->table->must_eat--; ///// gerer si on envoie 0 comme argument
        philo->last_meal = get_time();
        usleep(philo->table->time_to_eat * MILLISECOND);
        	//printf("miom miom & id %d\n",  philo->id);
        pthread_mutex_unlock(philo->fork_right);
        pthread_mutex_unlock(philo->fork_left);
		ft_print_msg(philo, PRINT_SLEEP);
        usleep(philo->table->time_to_sleep * MILLISECOND);
        	//printf("ron pshit & id %d\n",  philo->id);
		ft_print_msg(philo, PRINT_THINK);
    }
    philo->table->dead++;
    printf("dead : %d\n", philo->table->dead);
    return (NULL);
}
