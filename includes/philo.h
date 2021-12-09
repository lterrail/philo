#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <limits.h>
# include "libft.h"

# define SUCCESS		             1
# define ERROR			             0
# define ERROR_MALLOC               -2
# define ERROR_USAGE                -3

# define MILLISECOND                 1000
# define NB_PHILO                    2

# define PRINT_FORK                  0
# define PRINT_EAT                   1
# define PRINT_SLEEP                 2
# define PRINT_THINK                 3
# define PRINT_DIED                  4

typedef struct      s_philo
{
    int					id;
    pthread_mutex_t		*fork_left;
	pthread_mutex_t		*fork_right;
    pthread_mutex_t     *eats;
    long long int       last_meal;
    struct s_table      *table;
}					t_philo;

typedef struct      s_table
{
    t_philo         *philo;
    int nb_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int time_to_think;
    long long int begin_time;
    int           must_eat;
}					t_table;


#endif
