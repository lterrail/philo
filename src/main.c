#include "philo.h"

static long long int	get_time(void)
{
    struct timeval  current_time;

    gettimeofday(&current_time, NULL);
	return (current_time.tv_sec*1000 + current_time.tv_usec/1000);
}

static	void	ft_print_msg(t_philo *philo, int i)
{
	if (i == PRINT_FORK)
		printf("%lld   %d has taken a fork\n", get_time(), philo->id);
	if (i == PRINT_EAT)
		printf("%lld   %d is eating\n", get_time(), philo->id);
	if (i == PRINT_SLEEP)
		printf("%lld   %d is sleeping\n", get_time(), philo->id);
	if (i == PRINT_THINK)
		printf("%lld   %d is thinking\n", get_time(), philo->id);
	if (i == PRINT_DIED)
		printf("%lld   %d died\n", get_time(), philo->id);
}

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

        //printf("---------id philo :%d  - id  fork left: %d\n", table->philo[i].id,i);
        i++;
       // table->philo[i]->eats = malloc(sizeof(pthread_mutex_t));
        // if  (!table->philo->eats)
        //     return (ERROR_MALLOC);
    }
    // if  (table->nb_philo > 2 && table->nb_philo % 2 == 0)
    // {
    //     int x = 0;
    //     while (x < table->nb_philo  /  2)
    //     {
    //         pthread_mutex_init(table->philo[x].eats, NULL); 
    //     // pthread_mutex_init(table->philo[0].eats, NULL);  // initialisation mutex  du philo  0
    //         x++;
    //     }
    // }
    i = 0;
    while (i < table->nb_philo)
    {
        if (i != 0)
        {
            table->philo[i].fork_right = table->philo[i - 1].fork_left;
            //table->philo[i].eats = table->philo[0].eats;  // on donne le mutex aux autres philo
            //printf("ici : id philo A  :%d  - id  fork right: %d\n", table->philo[i].id, i - 1);
        }
        else
        {
            table->philo[i].fork_right = table->philo[table->nb_philo - 1].fork_left;
            //printf("laaaa : id philo :%d  - id  fork right: %d\n", table->philo[i].id,table->nb_philo  -  1);
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
	t_philo *philo;
    philo = (t_philo *)void_philo;
    // printf("----id philo :%d - %p - %p\n", philo->id, philo->fork_left, philo->fork_right);
    while (1) {
        pthread_mutex_lock(philo->fork_right);
		ft_print_msg(philo, PRINT_FORK); /////
        	//printf("right fork & id %d\n",  philo->id);
        pthread_mutex_lock(philo->fork_left);
		ft_print_msg(philo, PRINT_FORK);
        	//printf("left fork  & id %d\n",  philo->id);
        usleep(philo->table->time_to_eat * 10000);
        //printf("ICI: %d\n",  philo->table->time_to_eat);
        //pthread_mutex_lock(philo->eats);
        	//printf("miom miom & id %d\n",  philo->id);
		ft_print_msg(philo, PRINT_EAT);
        pthread_mutex_unlock(philo->fork_right);
        pthread_mutex_unlock(philo->fork_left);
        //pthread_mutex_unlock(philo->eats);
        usleep(philo->table->time_to_sleep * 5000);
        	//printf("ron pshit & id %d\n",  philo->id);
		ft_print_msg(philo, PRINT_SLEEP);
    }

    return (NULL);
}


// static long long int	elapsed_time(void)
// {
// 	long long int  start_time;
// 	long long int  end_time;

// 	start_time = get_time();
// 	end_time = get_time();
// 	return (end_time - start_time);
// }


int main(int ac, char **av)
{
    pthread_t threads[2];
    t_table *table;

    //printf("%16lld %s\n", 100000000, "toto");  //has eaten  /  print propre  et ms affichage 

    int i = 0;
	int ret;
    table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (ERROR_MALLOC);
    ft_parse_arg(av, table);
    if (init_table(table) == ERROR)
        return (ERROR);
    else
		table->begin_time = get_time();
    while (i < table->nb_philo)
    {
        ret = pthread_create(&(threads[i]), NULL, ft_start, &(table->philo[i]));
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

// faire  une condition  d'arret  de jeu (philo dead)

// savoir si mutex eats
