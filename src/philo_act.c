#include "../include/philosopher.h"

// ◦timestamp_in_ms X has taken a fork
// ◦timestamp_in_ms X is eating
// ◦timestamp_in_ms X is sleeping
// ◦timestamp_in_ms X is thinking
// ◦timestamp_in_ms X died

int	check_fork_state(t_philo *philo)
{
	if (philo->args->forks[philo->id - 1] == 1 && philo->args->forks[philo->id] == 1)
		return (1);
	return (0);
}

void	releasefork(t_philo *philo)
{
		philo->args->forks[philo->id - 1] = 0;
		philo->args->forks[philo->id] = 0;
}

void	eat(t_philo *philo)
{
	takeforks(philo);
	if (check_fork_state(philo) == 1)
	{
		printf("%d %d is eating\n", getms(philo), philo->id);
		usleep((philo->t_to_eat * 1000));
		philo->t_s_last_meal = 0;
	}
	else
		printf("%d %d could not eat\n", getms(philo), philo->id);
	releasefork(philo);
}

void	think(t_philo *philo)
{
	printf("%d %d is thinking\n", getms(philo), philo->id);
	getms(philo);
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
	if ((philo->id % 2) == 0)
		eat(philo);
	think(philo);
	f_sleep(philo);
	return ((void *) philo);
}
