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

// A supprimer : ?
# define END_OF_GAME				9

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
    long long int       last_meal;
    struct s_table		*table;
}					t_philo;

typedef struct      s_table
{
    long long int	begin_time;
    t_philo			*philo;
    int				nb_philo;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
    int				time_to_think;
    int				must_eat;
    int				dead;
	pthread_t		*threads;

}					t_table;

// Time management
long long int	get_time(void);
long long int	elapsed_time(t_philo *philo);

// Print messages and clean exit
void	ft_print_msg(t_philo *philo, int i);
void	ft_print_error(int err);
void	ft_quit(t_table *table, int err);

// Initialization
int		init_table(t_table *table);

// Parsing and start
int		ft_parse_arg(char **av, int ac, t_table *table);
void	*ft_start(void *void_philo);

#endif
