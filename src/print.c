#include "philo.h"

void	ft_print_msg(t_philo *philo, int i)
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
