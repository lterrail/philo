#include "philo.h"

static void     *ft_check_death(void *void_table)
{
    t_table *table;
    table = (t_table *)void_table;
    while (1)
    {
		if (table->id_philo_who_just_died >= 0)
		{
			ft_print_msg(&(table->philo[table->id_philo_who_just_died]), PRINT_DIED);
			table->id_philo_who_just_died = -1;
			// ici quitter
		}
		if (table->dead == table->nb_philo)
			return (NULL);
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
    int death = pthread_create(&(table->threads[table->nb_philo]), NULL, ft_check_death, table);
	if (death != 0)
        return (ERROR);
    while (table->dead != table->nb_philo) // > 0 arrete bien le jeu mais bouffe le print de mort
    {
        usleep(MILLISECOND);
    }
	ft_quit(table, SUCCESS);
    return (SUCCESS);
}

// faire  une condition  d'arret  de jeu ( 1 philo dead)
