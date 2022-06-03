#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// args: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, (all in milliseconds)


typedef struct s_philo
{
	pthread_mutex_t	pick_r_fork;
	pthread_mutex_t pick_l_fork;
	int			*forks;
	int			philo_id;
	int			t_to_die;
	int			t_to_eat;
	int			t_to_sleep;
	int			n_times_eat;
}	t_philo;

typedef struct s_args
{
	pthread_t	*philo_thread;
	t_philo		*philo;
	int			n_philo;
}	t_args;

int		ft_atoi(const char *str);
void	create_philos(t_args *args);
void	initargs(char *argv[], t_args *args);
void	checkargsnum(int argc);
void	check(int argc, char *argv[]);
void	check_validity(char *argv[]);
void	*philo_act(void *arg);
void    initphilo(char *argv[], t_args *args, t_philo *philo);