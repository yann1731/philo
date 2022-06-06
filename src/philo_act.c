#include "../include/philosopher.h"

// ◦timestamp_in_ms X has taken a fork
// ◦timestamp_in_ms X is eating
// ◦timestamp_in_ms X is sleeping
// ◦timestamp_in_ms X is thinking
// ◦timestamp_in_ms X died

void	eat(t_philo *philo)
{
	printf("Philo")
}

void	think(t_philo *philo)
{

}

void	sleep(t_philo *philo)
{

}

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
