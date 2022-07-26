/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:19:39 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/18 15:19:42 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdarg.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# define FALSE 0
# define TRUE 1

typedef struct s_args	t_args;
typedef struct s_philo	t_philo;

typedef struct s_philo
{
	int			id;
	long long	t_to_die;
	long long	t_to_eat;
	long long	t_to_sleep;
	long long	n_times_to_eat;
	int			n_meals_eaten;
	int			t_last_meal;
	int			t_cur_meal;
	int			left_fork;
	int			right_fork;
	int			full;
	t_args		*args;
}	t_philo;

typedef struct s_args
{
	pthread_t		*philo_thread;
	t_philo			*philo;
	long long		start_time;
	long long		n_philo;
	int				is_dead;
	int				check_meals;
	int				argc;
	int				error;
	pthread_mutex_t	write_mut;
	pthread_mutex_t	*forks;
	pthread_mutex_t	eating;
	pthread_mutex_t	check_dead;
}	t_args;

//check_utils.c
int			check_full(t_args *args);
void		check_philo_status(t_args *args);
void		checkdeath(t_philo *philo);
void		check(char *argv[], t_args *args);
int			checkintlimit(char *argv[]);

//end_utils.c
void		end_philo(t_args *args);
void		freeall(t_args *args);
void		freeargs(t_args *args);
void		destroy_mutex(t_args *args);

//error_utils.c
int			check_validity(char *argv[]);

//init_utils.c
void		initargs(int argc, char *argv[], t_args *args);
void		initphilo(char *argv[], t_args *args);

//misc_utils.c
long long	ft_atol(const char *str);
long long	get_start_time(void);
long long	get_ts(t_args *args);
void		my_sleep(t_philo *philo, int time_to_wait);
void		print(t_philo *philo, char *action);

//philo_act.c
void		eat(t_philo *philo);
void		think(t_philo *philo);
void		f_sleep(t_philo *philo);
void		*philo_act(void *arg);

//thread_utils.c
void		create_philos(t_args *args);
void		*single_philo_act(void	*arg);
void		single_philo(t_philo *philo);

#endif
