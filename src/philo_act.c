#include "../include/philosopher.h"

void	*philo_act(void *arg)
{
	t_philo *philo;
	philo = (t_philo *) arg;

	printf("%d\n", philo->philo_id);
	printf("%d\n", philo->t_to_die);
	printf("%d\n", philo->t_to_eat);
	printf("%d\n", philo->t_to_sleep);

	return ((void *) philo->forks);
}
