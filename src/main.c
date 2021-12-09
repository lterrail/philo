#include "philo.h"

static int ft_init_philosophers(t_table *table)
{
    int i;

    i = -1;
    while (++i < table->nb_philo)
    {
        table->philo[i].id = i;
        table->philo[i].last_meal = table->begin_time;
        if (!(table->philo[i].fork_left = malloc(sizeof(pthread_mutex_t))))
            return (ERROR);
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
    return (SUCCESS);
}

static int ft_init_table(t_table *table)
{
    int i;

    i = -1;
    if (!(table->philo = (t_philo *)malloc(sizeof(t_philo) * table->nb_philo)))
        return (ERROR);
    if (!(table->threads = (pthread_t *)malloc(sizeof(pthread_t) * table->nb_philo)))
        return (ERROR);
    if (ft_init_philosophers(table) == ERROR)
        return (ERROR);
	table->begin_time = get_time();
    while (++i < table->nb_philo)
    {
        table->philo[i].table = table;
    }
    return (SUCCESS);
}

// faut il ajouter ft_atoi(av[5]) pour l'arguement optional nb_meal ?
static int     ft_parse_arg(int ac, char **av, t_table  *table)
{
    if (ac != 5)
        return (ERROR);
    table->nb_philo = ft_atoi(av[1]);
    table->time_to_die = ft_atoi(av[2]);
    table->time_to_eat = ft_atoi(av[3]);
    table->time_to_sleep = ft_atoi(av[4]);
    if  (!table->nb_philo ||  !table->time_to_die ||  !table->time_to_eat ||  !table->time_to_sleep)
        return (ERROR);
    if  (table->nb_philo < 2)
        return (ERROR);
    return (SUCCESS);
}

int             main(int ac, char **av)
{
    t_table *table;

    table = (t_table *)malloc(sizeof(t_table));
    if (!table)
    {
        printf("Error\nMalloc failed\n");
        return (ERROR);
    }
    if (ft_parse_arg(ac, av, table) == ERROR)
    {
        printf("Error\n\tusage: ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep]\n");
        return (ERROR);
    }
    if (ft_init_table(table) == ERROR)
    {
        printf("Error\nMalloc failed\n");
        return (ERROR);
    }
    if (ft_play(table) == ERROR)
    {
        printf("Error\nGame crashed\n");
        return (ERROR);
    }
    return (SUCCESS);
}
