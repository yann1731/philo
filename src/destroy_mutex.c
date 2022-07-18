#include "../include/philosopher.h"

void	destroy_mutex(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->n_philo)
		pthread_mutex_destroy(&args->forks[i]);
	pthread_mutex_destroy(&args->check_dead);
	pthread_mutex_destroy(&args->write_mut);
}