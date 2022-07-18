#include "../include/philosopher.h"

void	initphilo(char *argv[], t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->n_philo)
	{
		args->philo[i].t_to_die = ft_atoi(argv[2]);
		args->philo[i].t_to_eat = ft_atoi(argv[3]);
		args->philo[i].t_to_sleep = ft_atoi(argv[4]);
		if (argv[5] != NULL)
			args->philo[i].n_times_to_eat = ft_atoi(argv[5]);
		args->philo[i].id = i + 1;
		args->philo[i].t_last_meal = 0;
		args->philo[i].args = args;
		args->philo[i].t_cur_meal = 0;
		args->philo[i].left_fork = i;
		args->philo[i].right_fork = (i + 1) % args->n_philo;
	}
}
