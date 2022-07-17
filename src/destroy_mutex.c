#include "../include/philosopher.h"

void	destroy_mutex(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->n_philo)
	{
		pthread_mutex_destroy(&args->philo[i].pick_forks);
		pthread_mutex_destroy(&args->philo[i].check_dead);
	}
}