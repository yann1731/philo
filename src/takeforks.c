#include "../include/philosopher.h"

void	takeforks(t_philo *philo)
{
	pthread_mutex_lock(&philo->pick_forks);
	if (philo->args->forks[philo->id - 1] == 0)
	{
		philo->args->forks[philo->id - 1] = 1;
		printf("%d %d has taken a fork\n", getms(philo), philo->id);
	}
	else
		printf("%d %d could not take a fork\n", getms(philo), philo->id);
	if (philo->args->forks[philo->id] == 0)
	{
		philo->args->forks[philo->id] = 1;
		printf("%d %d has taken a fork\n", getms(philo), philo->id);
	}
	else
		printf("%d %d could not take a fork\n", getms(philo), philo->id);
	pthread_mutex_unlock(&philo->pick_forks);
}