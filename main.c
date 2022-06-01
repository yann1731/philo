#include "philosopher.h"

/*  Allowed functions	*/

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

/*	Messages to be printed when changing states	*/

// ◦ timestamp_in_ms X has taken a fork
// ◦ timestamp_in_ms X is eating
// ◦ timestamp_in_ms X is sleeping
// ◦ timestamp_in_ms X is thinking
// ◦ timestamp_in_ms X died

// args: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, (all in milliseconds)

// void	eat(t_philo *philo)
// {

// }

// void	think(t_philo *philo)
// {

// }

// void	sleep(t_philo *philo)
// {

// }

// void	*philo_act(void *philo)
// {
// 	printf("hello from philo\n");

// 	return (0);
// }

int	main(int argc, char *argv[])
{
	t_philo	philo;

	check(argc, argv);
	convertargs(argv, &philo);
	create_philos(&philo);
	return (0);
}
