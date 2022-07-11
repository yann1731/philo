#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdarg.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# define FALSE 0
# define TRUE 1

// args: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, (all in milliseconds)
typedef struct s_args t_args;
typedef struct s_philo t_philo;

typedef struct s_philo
{
	int				id;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				n_times_to_eat;
	int				n_meals_eaten;
	int				t_s_last_meal;
	int				t_cur_meal;
	struct timeval	current_time;
	pthread_mutex_t	pick_forks;
	pthread_mutex_t	check_dead;
	t_args			*args;
}	t_philo;

typedef struct s_args
{
	pthread_t		*philo_thread;
	t_philo			*philo;
	struct timeval	*start_time;
	int				*forks;
	int				n_philo;
	int				is_dead;
	int				check_meals;
}	t_args;

int		ft_atoi(const char *str);
void	create_philos(t_args *args);
void	initargs(char *argv[], t_args *args);
void	checkargsnum(int argc);
void	check(int argc, char *argv[]);
void	check_validity(char *argv[]);
void	*philo_act(void *arg);
void    initphilo(char *argv[], t_args *args);
int		getms(t_philo *philo);
void	fuckoff(void);
void	freeall(t_args *args);
//void	init_mutex(t_args *args);
void	takeforks(t_philo *philo);
void	checkdeath(t_philo *philo);

#endif