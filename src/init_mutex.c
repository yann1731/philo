#include "../include/philosopher.h"

void	init_mutex(t_philo *philo)
{
	pthread_mutex_init(&philo->pick_l_fork, NULL);
	pthread_mutex_init(&philo->pick_r_fork, NULL);
	pthread_mutex_init(&philo->check_death, NULL);
}