#include "philosopher.h"

void	convertargs(char *argv[], t_philo *philo)
{
	int	i;
	int	n_philo;

	i = -1;
	n_philo = ft_atoi(argv[1]);
	philo = malloc(n_philo * sizeof(t_philo));
	philo->n_philo = n_philo;
	philo->forks = malloc(philo->n_philo * sizeof(int));
	philo->t_to_die = ft_atoi(argv[2]);
	philo->t_to_eat = ft_atoi(argv[3]);
	philo->t_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		philo->n_times_eat = ft_atoi(argv[5]);
	else
		philo->n_times_eat = -1;
	philo->forks = malloc(philo->n_philo * sizeof(int));
	while (++i < philo->n_philo)
		philo->forks[i] = 1;
	pthread_mutex_init(&philo->pick_r_fork, NULL);
	pthread_mutex_init(&philo->pick_l_fork, NULL);
}
