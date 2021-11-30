#include "philo.h"

static int init_table(t_table *table)
{
    int i;

    i = 0;
    
    if (!(table->philo = (t_philo *)malloc(sizeof(t_philo) * table->nb_philo)))
        return (0);

    while (i < table->nb_philo)
    {
        table->philo[i].id = i;
        if (!(table->philo[i].fork_left = malloc(sizeof(pthread_mutex_t))))
            return (ERROR_MALLOC);
        //printf("%p\n", table->philo[i].fork_left);
		pthread_mutex_init(table->philo[i].fork_left, NULL);
        //printf("id philo :%d  - id  fork left: %d\n", table->philo[i].id,i);
        i++;
        table->philo->eats = malloc(sizeof(pthread_mutex_t));
        if  (!table->philo->eats)
            return (ERROR_MALLOC);
    }
    pthread_mutex_init(table->philo[0].eats, NULL);  // initialisation mutex  du philo  0
    i = 0;
    while (i < table->nb_philo)
    {
        if (i != 0)
        {
            table->philo[i].fork_right = table->philo[i - 1].fork_left;
            table->philo[i].eats = table->philo[0].eats;  // on donne le mutex aux autres philo
            //printf("id philo A  :%d  - id  fork right: %d\n", table->philo[i].id, i - 1);
        }
        else
        {
            table->philo[i].fork_right = table->philo[table->nb_philo - 1].fork_left;
            //printf("id philo :%d  - id  fork right: %d\n", table->philo[i].id,table->nb_philo  -  1);
        }
        i++;
    }
    i = 0;
    while (i < table->nb_philo)
    {
        table->philo[i].table = table;
        i++;
    }
    return (SUCCESS);
}

static int     ft_parse_arg(char **av, t_table  *table)
{
    table->nb_philo = ft_atoi(av[1]);
    table->time_to_die = ft_atoi(av[2]);
    table->time_to_eat = ft_atoi(av[3]);
    table->time_to_sleep = ft_atoi(av[4]); //  + argument  optionnel ?
    if  (!table->nb_philo ||  !table->time_to_die ||  !table->time_to_eat ||  !table->time_to_sleep)
        return (ERROR); // si ca  peut  fail ?
    if  (table->nb_philo < 2)
        return (ERROR_USAGE);
    return (SUCCESS);
}

static void    *ft_start(void *void_philo)
{

        puts("NOOO");  
	t_philo *philo;
    philo = (t_philo *)void_philo;
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(philo->fork_right);

    printf("left fork & id %d\n",  philo->id);
    printf("right fork  & id %d\n",  philo->id);

    usleep(philo->table->time_to_eat * MILLISECOND);
    printf("ICI: %d\n",  philo->table->time_to_eat);
	pthread_mutex_lock(philo->eats);
    printf("miom miom & id %d\n",  philo->id);

	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->eats);

    return (NULL);
}

int main(int ac, char **av)
{
    pthread_t threads[2];
    t_table *table;

    int i = 0;
    table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (ERROR_MALLOC);
    ft_parse_arg(av, table);
    if (init_table(table) == ERROR)
        return (ERROR);
    while (i < table->nb_philo)
    {
        int ret;
        
        ret  =  pthread_create(&(threads[i]), NULL, ft_start, &(table->philo[i]));
        if (ret != 0)
            return (ERROR);
        usleep(10);
        i++;
    }

    while (1)
    {
        sleep(1);
    }
    
    (void)ac;
    //(void)av;
    return (SUCCESS);
}


//  faire  fonction de time 
// -> timestamp &&  elasped time (after - now)

// faire  une  fonction de display de message  coolax

// faire  une condition  d'arret  de jeu (philo dead)

//  debugger forks

// savoir si mutex eats
