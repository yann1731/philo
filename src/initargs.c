#include "../include/philosopher.h"

void	initargs(int argc, char *argv[], t_args *args)
{
	int	i;

	i = -1;
	args->n_philo = ft_atoi(argv[1]);
	args->philo = malloc(args->n_philo * sizeof(t_philo));
	args->philo_thread = malloc(args->n_philo * sizeof(pthread_t));
	args->forks = malloc(args->n_philo * sizeof(pthread_mutex_t));
	args->is_dead = FALSE;
	if (argc == 6)
		args->check_meals = TRUE;
	else
		args->check_meals = FALSE;
	pthread_mutex_init(&args->write_mut, NULL);
	pthread_mutex_init(&args->check_dead, NULL);
	while (++i < args->n_philo)
		pthread_mutex_init(&args->forks[i], NULL);
	pthread_mutex_init(&args->eating, NULL);
	args->start_time = get_start_time();
	args->argc = argc;
	initphilo(argv, args);
}
