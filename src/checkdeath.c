#include "../include/philosopher.h"

void	checkdeath(t_philo *philo)
{
	pthread_mutex_lock(&philo->check_dead);
	if ((get_ts(philo) - philo->t_s_last_meal) > philo->t_to_die)
	{
		philo->args->is_dead = TRUE;
		print(philo, "has died");
	}
	pthread_mutex_unlock(&philo->check_dead);
}