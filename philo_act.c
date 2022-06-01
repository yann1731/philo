#include "philosopher.h"

void	*philo_act(void *arg)
{
	t_philo *philo;
	philo = (t_philo *) arg;

	return ((void *) philo->forks);
}
