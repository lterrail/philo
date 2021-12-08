#include "philo.h"

static int init_table(t_table *table)
{
    int i;

    if (!(table->philo = (t_philo *)malloc(sizeof(t_philo) * table->nb_philo)))
        return (ERROR_MALLOC);
    i = -1;
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
	table->begin_time = get_time();
    return (SUCCESS);
}

static int     ft_parse_arg(int ac, char **av, t_table  *table)
{
    if (ac != 5)
        return (ERROR_USAGE);
    table->nb_philo = ft_atoi(av[1]);
    table->time_to_die = ft_atoi(av[2]);
    table->time_to_eat = ft_atoi(av[3]);
    table->time_to_sleep = ft_atoi(av[4]); //  + argument  optionnel ?
    if  (!table->nb_philo ||  !table->time_to_die ||  !table->time_to_eat ||  !table->time_to_sleep)
        return (ERROR_USAGE); // si ca  peut  fail ?
    if  (table->nb_philo < 2)
        return (ERROR_USAGE);
    return (SUCCESS);
}

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
    // philo->table->dead = id_philo
    ft_print_msg(philo, PRINT_DIED);
    return (NULL);
}


int main(int ac, char **av)
{
    pthread_t threads[4]; /// UN PROBLEMO SSS ACQUIIII
    t_table *table;
    int     i;
	int     ret;

    table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (ERROR_MALLOC);
    ret = ft_parse_arg(ac, av, table);
    if (ret < 0)
        return (ret);
    ft_parse_arg(ac, av, table);
    if (init_table(table) == ERROR)
        return (ERROR);
    i = -1;
    while (++i < table->nb_philo)
    {
        ret = pthread_create(&(threads[i]), NULL, ft_start, &(table->philo[i]));
        if (ret != 0)
            return (ERROR);
        usleep(MILLISECOND); // a verifier si ok ou pas
        i++;
    }
    while (1)
    {
        // if (table->is_dead > 0)
        // {
        //     pthread_detach(threads[table->is_dead]);
        //     pthread_join(threads[table->is_dead]);
        // }
    }
    return (SUCCESS);
}

// faire  une condition  d'arret  de jeu (philo dead)

// savoir si mutex eats

// faire un thread de plus qui verifie l'etat de mort des philo
