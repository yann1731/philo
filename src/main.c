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

	args = malloc(sizeof(t_args));
	check(argc, argv);
	initargs(argc, argv, args);
	create_philos(args);
	end_philo(args);
	return (0);
}
