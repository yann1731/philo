#include "../include/philosopher.h"

void	create_philos(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->n_philo)
		pthread_create(&args->philo_thread[i], NULL, &philo_act, (void *) &args->philo[i]);
	i = -1;
	while (++i < args->n_philo)
		pthread_join(args->philo_thread[i], NULL);
}
