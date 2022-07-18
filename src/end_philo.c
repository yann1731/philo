#include "../include/philosopher.h"

void	end_philo(t_args *args)
{
	int i;

	i = -1;
	while (args->is_dead == FALSE)
	{
	}
	while (++i < args->n_philo)
		pthread_join(args->philo_thread[i], NULL);
	destroy_mutex(args);
	freeall(args);
}