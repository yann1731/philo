#include "../include/philosopher.h"

void	print(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->args->write_mut);
	printf("%lld %d %s\n", get_ts(philo), philo->id, action);
	pthread_mutex_unlock(&philo->args->write_mut);
}