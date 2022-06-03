#include "../include/philosopher.h"

void	initargs(char *argv[], t_args *args)
{
	int	n_philo;

	n_philo = ft_atoi(argv[1]);
	args->philo = malloc(n_philo * sizeof(t_philo));
	args->philo_thread = malloc(n_philo * sizeof(pthread_t));
	args->n_philo = n_philo;
	initphilo(argv, args, args->philo);
}
