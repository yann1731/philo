#include "../include/philosopher.h"

/*  Allowed functions	*/

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

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
	t_args			args;

	check(argc, argv);
	initargs(argv, &args);
	create_philos(&args);
	return (0);
}
