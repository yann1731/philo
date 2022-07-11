#include "../include/philosopher.h"

void	checkdeath(t_philo *philo)
{
	pthread_mutex_lock(&philo->check_dead);
	printf("time since last meal: %d\n", getms(philo));
	if ((getms(philo) - philo->t_s_last_meal) > philo->t_to_die)
	{
		philo->args->is_dead = TRUE;
		printf("%d %d has died\n", getms(philo), philo->id);
	}
	pthread_mutex_unlock(&philo->check_dead);
}