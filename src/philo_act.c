#include "../include/philosopher.h"

// ◦timestamp_in_ms X has taken a fork
// ◦timestamp_in_ms X is eating
// ◦timestamp_in_ms X is sleeping
// ◦timestamp_in_ms X is thinking
// ◦timestamp_in_ms X died

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->take_forks);
	takeforks(philo);
	printf("%d %d is eating\n", getms(philo), philo->id);
	pthread_mutex_unlock(&philo->args->take_forks);
	usleep((philo->t_to_eat * 1000));
}

void	think(t_philo *philo)
{
	printf("%d %d is thinking\n", getms(philo), philo->id);
}

void	f_sleep(t_philo *philo)
{
	printf("%d %d is sleeping\n", getms(philo), philo->id);
	usleep((philo->t_to_sleep * 1000));
}

void	*philo_act(void *arg)
{
	t_philo *philo;
	philo = (t_philo *) arg;
	while (philo->args->is_dead == FALSE)
	{
	}
	return ((void *) philo);
}
