#include "../include/philosopher.h"

void	initargs(char *argv[], t_args *args)
{
	int	i;

	i = -1;
	args->n_philo = ft_atoi(argv[1]);
	args->philo = malloc(args->n_philo * sizeof(t_philo));
	args->philo_thread = malloc(args->n_philo * sizeof(pthread_t));
	args->forks = malloc(args->n_philo * sizeof(int));
	while (++i < args->n_philo)
		args->forks[i] = 0;
	args->is_dead = FALSE;
	args->start_time = malloc(sizeof(struct timeval));
	args->check_meals = FALSE;
	gettimeofday(args->start_time, NULL);
	initphilo(argv, args);
}
