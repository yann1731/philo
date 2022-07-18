#include "../include/philosopher.h"

// ◦timestamp_in_ms X has taken a fork
// ◦timestamp_in_ms X is eating
// ◦timestamp_in_ms X is sleeping
// ◦timestamp_in_ms X is thinking
// ◦timestamp_in_ms X died

// int	check_fork_state(t_philo *philo)
// {
// 	if (philo->args->forks[philo->id - 1] == 1 && philo->args->forks[philo->id] == 1)
// 		return (1);
// 	return (0);
// }

// void	releasefork(t_philo *philo)
// {
// 		philo->args->forks[philo->id - 1] = 0;
// 		philo->args->forks[philo->id] = 0;
// }

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->forks[philo->left_fork]);
	print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->args->forks[philo->right_fork]);
	print(philo, "has taken a fork");
	print(philo, "is eating");
	philo->t_last_meal = get_ts(philo->args);
	philo->n_meals_eaten++;
	my_sleep(philo, philo->t_to_eat);
	pthread_mutex_unlock(&philo->args->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->args->forks[philo->right_fork]);
}

void	think(t_philo *philo)
{
	if (philo->args->is_dead == FALSE)
	{
		print(philo, "is thinking");
	}
}

void	f_sleep(t_philo *philo)
{
	if (philo->args->is_dead == FALSE)
	{
		print(philo, "is sleeping");
		my_sleep(philo, philo->t_to_sleep);
	}
}

void	*philo_act(void *arg)
{
	t_philo *philo;
	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		my_sleep(philo, philo->t_to_eat);
	while (philo->args->is_dead == FALSE)
	{
		checkdeath(philo);
		eat(philo);
		think(philo);
		f_sleep(philo);
	}
	return ((void *) philo);
}
