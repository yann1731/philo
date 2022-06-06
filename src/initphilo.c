#include "../include/philosopher.h"

void	initphilo(char *argv[], t_args *args, t_philo *philo)
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
		philo[i].t_to_die = ft_atoi(argv[2]);
		philo[i].t_to_eat = ft_atoi(argv[3]);
		philo[i].t_to_sleep = ft_atoi(argv[4]);
		if (argv[5] != NULL)
			philo[i].n_times_eat = ft_atoi(argv[5]);
		philo[i].philo_id = i + 1;
		philo[i].start_time.tv_sec = seconds;
		philo[i].start_time.tv_usec = usecs;
		pthread_mutex_init(&philo[i].pick_l_fork, NULL);
		pthread_mutex_init(&philo[i].pick_r_fork, NULL);
	}
}
