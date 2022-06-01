#include "philosopher.h"

void	create_philos(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->n_philo)
		pthread_create(&philo->philo[i], NULL, &philo_act, (void *) philo);
	i = -1;
	while (++i < philo->n_philo)
		pthread_join(philo->philo[i], NULL);
}
