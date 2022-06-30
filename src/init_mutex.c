#include "../include/philosopher.h"

void	init_mutex(t_args *args)
{
	pthread_mutex_init(&args->pick_forks, NULL);
	pthread_mutex_init(&args->check_death, NULL);
}