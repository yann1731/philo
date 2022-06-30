#include "../include/philosopher.h"

void	freeall(t_args *args)
{
	free(args->philo_thread);
	free(args->philo);
	free(args->forks);
	free(args->start_time);
	free(args);
}