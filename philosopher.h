#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// args: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, (all in milliseconds)

typedef struct s_args
{
	int	n_philo;
	int	n_forks;
	int	t_to_die;
	int	t_to_eat;
	int	t_to_sleep;
}	t_args;

typedef struct s_philo
{
	pthread_t	philo;
	t_args		args;
}	t_philo;
