#include "philo.h"

static void ft_monitor(t_table *table)
{
	int i;

	i = -1;
    while (1)
    {
		while (++i < table->nb_philo)
		{
			if (get_time() - table->philo[i].last_meal >= table->time_to_die)
			{
				ft_print_msg(&(table->philo[i]), PRINT_DIED);
				table->dead = 1;
				return ;
			}
			if (table->must_eat <= 0)
			{
				ft_print_msg(&(table->philo[i]), PRINT_END_OF_GAME);
				table->dead = 1;
				return ;
			}
		}
		i = -1;
    }
}

int main(int ac, char **av)
{
    t_table *table;
    int i = 0;
	int ret;
	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (ERROR_MALLOC);
	if (ft_parse_arg(av, ac, table) == ERROR)
		return (ERROR_USAGE); // mettre une erreur usage
	if (init_table(table) == ERROR)
		return (ERROR);
	while (i < table->nb_philo)
    {
		ret = pthread_create(&(table->threads[i]), NULL, ft_start, &(table->philo[i]));
		if (ret != 0)
            return (ERROR);
        usleep(100); // a verifier si ok ou pas
        i++;
    }
	ft_monitor(table);
    while (1)
	{
		if (table->dead == table->nb_philo + 1)
		{
			ft_quit(table, SUCCESS);
			return (SUCCESS);
		}
	}
}
