#include "philo.h"

static long long int	get_time(void)
{
    struct timeval  current_time;

    gettimeofday(&current_time, NULL);
	return (current_time.tv_sec*1000 + current_time.tv_usec/1000);
}

static long long int	elapsed_time(t_philo *philo)
{
	long long int  end_time;

	end_time = get_time();
	return (end_time - philo->table->begin_time);
}

static	void	ft_print_msg(t_philo *philo, int i)
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

static int init_table(t_table *table)
{
    int i;

    i = 0;
    
    if (!(table->philo = (t_philo *)malloc(sizeof(t_philo) * table->nb_philo)))
        return (0);

    while (i < table->nb_philo)
    {
        table->philo[i].id = i;
        table->philo[i].last_meal = table->begin_time;
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
	table->begin_time = get_time();
    return (SUCCESS);
}

static int     ft_parse_arg(char **av, int ac,  t_table  *table)
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
    if  (table->nb_philo < 2)
        return (ERROR_USAGE);
    return (SUCCESS);
}

static void    *ft_start(void *void_philo)
{
	t_philo *philo;
    philo = (t_philo *)void_philo;
    // printf("----id philo :%d - %p - %p\n", philo->id, philo->fork_left, philo->fork_right);
    while (get_time() >= (philo->table->time_to_die * MILLISECOND + philo->last_meal) && philo->table->must_eat) /////
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
        //printf("ICI: %d\n",  philo->table->time_to_eat);
        //pthread_mutex_lock(philo->eats);
        	//printf("miom miom & id %d\n",  philo->id);
        pthread_mutex_unlock(philo->fork_right);
        pthread_mutex_unlock(philo->fork_left);
        //pthread_mutex_unlock(philo->eats);
		ft_print_msg(philo, PRINT_SLEEP);
        usleep(philo->table->time_to_sleep * MILLISECOND);
        	//printf("ron pshit & id %d\n",  philo->id);
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

    //printf("%16lld %s\n", 100000000, "toto");  //has eaten  /  print propre  et ms affichage 

    int i = 0;
	int ret;
    table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (ERROR_MALLOC);
    if (ft_parse_arg(av, ac, table) == ERROR)
        return (ERROR); // mettre une erreur usage
    if (init_table(table) == ERROR)
        return (ERROR);
    
    //     //usleep(100*MILLISECOND);
    // puts("BEFOOOORE");
    // //detatch d'abord
    // if ((pthread_detach(threads[0]) != 0))
    //     return (ERROR);
    // pthread_join(threads[0], NULL);
    // puts("FREDO DEAD");


    // premier thread qui check la mort de tous les joueurs 
    while (i < table->nb_philo)
    {
        ret = pthread_create(&(threads[i]), NULL, ft_start, &(table->philo[i]));
        if (ret != 0)
            return (ERROR);
        usleep(MILLISECOND); // a verifier si ok ou pas
        i++;
        pthread_detach(threads[i]);
    }
    while (1){}
    return (SUCCESS);
}

// faire  une condition  d'arret  de jeu (philo dead)

// savoir si mutex eats

// faire un thread de plus qui verifie l'etat de mort des philo
