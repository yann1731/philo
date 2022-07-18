#include "../include/philosopher.h"

int	checkdeath(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->check_dead);
	if ((get_ts(philo->args) - philo->t_last_meal) >= philo->t_to_die)
	{
		philo->args->is_dead = TRUE;
		printf("%lld %d has died\n", get_ts(philo->args), philo->id);
		pthread_mutex_unlock(&philo->args->check_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->args->check_dead);
	return (0);
}