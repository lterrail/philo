#include "philo.h"


static void    *ft_start(void *void_philo)
{
	t_philo *philo;

    philo = (t_philo *)void_philo;
    while (get_time() >= (philo->table->time_to_die * MILLISECOND + philo->last_meal))
    {
        pthread_mutex_lock(philo->fork_right);
		ft_print_msg(philo, PRINT_FORK);
        pthread_mutex_lock(philo->fork_left);
		ft_print_msg(philo, PRINT_FORK);
		ft_print_msg(philo, PRINT_EAT);
        philo->last_meal = get_time();
        usleep(philo->table->time_to_eat * MILLISECOND);
        pthread_mutex_unlock(philo->fork_right);
        pthread_mutex_unlock(philo->fork_left);
		ft_print_msg(philo, PRINT_SLEEP);
        usleep(philo->table->time_to_sleep * MILLISECOND);
		ft_print_msg(philo, PRINT_THINK);
    }
    ft_print_msg(philo, PRINT_DIED);
    return (NULL);
}

int         ft_play(t_table *table)
{
    int i;
    int ret;

    i =  -1;
    while (++i < table->nb_philo)
    {
        ret = pthread_create(&(table->threads[i]), NULL, ft_start, &(table->philo[i]));
        if (ret != 0)
            return (ERROR);
        usleep(MILLISECOND);
        i++;
    }
    while (1){}
}