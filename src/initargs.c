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
	args->check_meals = FALSE;
	pthread_mutex_init(&args->write_mut, NULL);
	args->start_time = get_start_time();
	initphilo(argv, args);
}
