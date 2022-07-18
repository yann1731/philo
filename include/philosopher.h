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
# define FALSE 0
# define TRUE 1

// args: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, (all in milliseconds)
typedef struct s_args t_args;
typedef struct s_philo t_philo;

typedef struct s_philo
{
	int			id;
	int			t_to_die;
	int			t_to_eat;
	int			t_to_sleep;
	int			n_times_to_eat;
	int			n_meals_eaten;
	int			t_last_meal;
	int			t_cur_meal;
	int			left_fork;
	int			right_fork;
	t_args		*args;
}	t_philo;

typedef struct s_args
{
	pthread_t		*philo_thread;
	t_philo			*philo;
	long long		start_time;
	int				n_philo;
	int				is_dead;
	int				check_meals;
	int				argc;
	pthread_mutex_t	write_mut;
	pthread_mutex_t	*forks;
	pthread_mutex_t eating;
	pthread_mutex_t check_dead;
}	t_args;

int			ft_atoi(const char *str);
void		create_philos(t_args *args);
void		initargs(int argc, char *argv[], t_args *args);
void		checkargsnum(int argc);
void		check(int argc, char *argv[]);
void		check_validity(char *argv[]);
void		*philo_act(void *arg);
void    	initphilo(char *argv[], t_args *args);
long long	get_ts(t_args *args);
void		fuckoff(void);
void		freeall(t_args *args);
void		takeforks(t_philo *philo);
void		checkdeath(t_philo *philo);
void		destroy_mutex(t_args *args);
long long	get_start_time(void);
void		print(t_philo *philo, char *action);
void		end_philo(t_args *args);
void		my_sleep(t_philo *philo, int time_to_wait);
void		check_philo_status(t_args *args);
void		single_philo(t_philo *philo);
void		*single_philo_act(void	*arg);

#endif
