#include "../include/philosopher.h"

/*  Allowed functions	*/

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

int	main(int argc, char *argv[])
{
	t_args	*args;
	int		i;

	i = -1;
	args = malloc(sizeof(t_args));
	check(argc, argv);
	initargs(argv, args);
	create_philos(args);
	if (argc == 4)
		while (args->is_dead == FALSE)
		{
		}
	else
		while (args->is_dead == FALSE && args->philo[args->n_philo].n_meals_eaten != args->philo->n_times_to_eat)
		{
		}
	while (++i < args->n_philo)
		pthread_join(args->philo_thread[i], NULL);
	freeall(args);
	return (0);
}
