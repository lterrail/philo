/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 05:21:59 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/19 15:12:18 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include "libft.h"

# define SUCCESS		             1
# define ERROR			             0
# define ERROR_MALLOC               -2
# define ERROR_USAGE                -3

# define MILLISECOND                 1000
# define NB_PHILO                    2

typedef struct      s_philo
{
    int					id;
    pthread_mutex_t		*fork_left;
	pthread_mutex_t		*fork_right;
    pthread_mutex_t     *eats;
    struct s_table      *table;
}					t_philo;

typedef struct      s_table
{
    t_philo         *philo;
    int nb_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int begin_time;
}					t_table;


#endif
