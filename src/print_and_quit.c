/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_quit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:17:37 by cnicolas          #+#    #+#             */
/*   Updated: 2021/12/10 16:13:09 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_msg(t_philo *philo, int i)
{
	if (i == PRINT_FORK)
		printf("%12lld ms  %d has taken a fork\n", elapsed_time(philo), philo->id);
	if (i == PRINT_EAT)
		printf("%12lld ms  %d is eating\n", elapsed_time(philo), philo->id);
	if (i == PRINT_SLEEP)
		printf("%12lld ms  %d is sleeping\n", elapsed_time(philo), philo->id);
	if (i == PRINT_THINK)
		printf("%12lld ms  %d is thinking\n", elapsed_time(philo), philo->id);
	if (i == PRINT_DIED)
		printf("%12lld ms  %d died\n", elapsed_time(philo), philo->id);
}

void	ft_print_error(int err)
{
	if (err == ERROR_MALLOC)
		printf("Error\nError Malloc\n");
	else if (err == ERROR_USAGE)
		printf("Error\nError Usage : ./philo number_of_philosophers time_to_die time_to_eat \
time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	else if (err == ERROR)
		printf("Error\n");
}

void ft_quit(t_table *table, int err)
{
	int	i;

	i = -1;
	ft_print_error(err);
	if (table)
	{
		if (table->philo)
		{
			while (++i < table->nb_philo)
			{
				if (table->philo[i].fork_left)
				{
					pthread_mutex_destroy(table->philo[i].fork_left);
					free(table->philo[i].fork_left);
				}
			}
			free(table->philo);
		}
		if (table->threads)
		{
			i = -1;
			while (++i <= table->nb_philo)
			{
				pthread_detach(table->threads[i]); ///leaks aleatoires :regarder les conditions detach precedentes car ne devaient pas etre validees
			}
			free(table->threads);
		}

		free(table);
	}
}