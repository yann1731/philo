#include "philosopher.h"

/*  Allowed functions	*/

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

/*	Messages to be printed when changing states	*/

// ◦ timestamp_in_ms X has taken a fork
// ◦ timestamp_in_ms X is eating
// ◦ timestamp_in_ms X is sleeping
// ◦ timestamp_in_ms X is thinking
// ◦ timestamp_in_ms X died

// args: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, (all in milliseconds)

void	philo(char *argv[])
{
	
}

void	create_philos(t_philo *philo)
{

}

void	convertargs(char *argv[], t_args *args)
{
	
}

void	checkargs(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (argv[++i])
	{
		while (argv[i][++j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			{
				write(2, "Must enter only positive numbers as arguments!", 46);
				exit(1);
			}
		}
		j = -1;
	}
}

void	checkargsreg(int argc)
{
	if (argc != 5)
	{
		write(STDERR_FILENO, "Not the right number of arguments", 33);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	checkargsreg(argc);
	checkargs(argv);

	return (0);
}
