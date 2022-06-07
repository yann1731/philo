#include "../include/philosopher.h"

void	initargs(char *argv[], t_args *args)
{
	args->n_philo = ft_atoi(argv[1]);
	args->philo = malloc(args->n_philo * sizeof(t_philo));
	args->philo_thread = malloc(args->n_philo * sizeof(pthread_t));
	args->forks = malloc(args->n_philo * sizeof(int));
	initphilo(argv, args);
}
