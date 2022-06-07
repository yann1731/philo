#include "../include/philosopher.h"

void	initphilo(char *argv[], t_args *args)
{
	int				n_philo;
	int				i;
	struct timeval	time;
	int				seconds;
	int				usecs;

	n_philo = args->n_philo;
	i = -1;
	gettimeofday(&time, NULL);
	seconds = time.tv_sec;
	usecs = time.tv_usec;
	while (++i < n_philo)
	{
		args->philo[i].t_to_die = ft_atoi(argv[2]);
		args->philo[i].t_to_eat = ft_atoi(argv[3]);
		args->philo[i].t_to_sleep = ft_atoi(argv[4]);
		if (argv[5] != NULL)
			args->philo[i].n_times_eat = ft_atoi(argv[5]);
		args->philo[i].philo_id = i + 1;
		args->philo[i].start_time.tv_sec = seconds;
		args->philo[i].start_time.tv_usec = usecs;
		args->philo->args = args;
		pthread_mutex_init(&args->philo[i].pick_l_fork, NULL);
		pthread_mutex_init(&args->philo[i].pick_r_fork, NULL);
	}
}
