#include "../include/philosopher.h"

void	takeleftfork(t_philo *philo)
{
	pthread_mutex_lock(&philo->pick_l_fork);
	
	pthread_mutex_unlock(&philo->pick_l_fork);
}