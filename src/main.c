#include "philo.h"

// static void     *ft_check_death(void *void_table)
// {
//     t_table *table;
//     table = (t_table *)void_table;
//     while (1)
//     {
// 		if (table->id_philo_who_just_died >= 0)
// 		{
// 			ft_print_msg(&(table->philo[table->id_philo_who_just_died]), PRINT_DIED);
// 			table->id_philo_who_just_died = -1;
// 			//return (NULL);
// 			// ici quitter
// 			//ft_quit(table, SUCCESS);
// 		}
// 		if (table->dead == table->nb_philo)
// 			return (NULL);
//     }
// }

void monitor_game(t_table *table)
{
    int i;

    while (1)
    {
        i = -1;
        while (++i < table->nb_philo)
        {
            if (get_time() >= (table->time_to_die * MILLISECOND + table->philo[i].last_meal) && table->must_eat)
            {
                continue ;
            } else {
                ft_print_msg(&(table->philo[i]), PRINT_DIED);
                table->dead = 1;
                return ;
            }
        }
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
        usleep(MILLISECOND); // a verifier si ok ou pas
        i++;
    }
    monitor_game(table);
    while (1) {
        if (table->dead == table->nb_philo + 1)
        {
            printf("%d-%d\n", table->nb_philo + 1,  table->dead);
            ft_quit(table, SUCCESS);
            return (SUCCESS);
        }
    }
}

