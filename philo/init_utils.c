/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:09:58 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/19 10:10:01 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosopher.h"

void	initargs(int argc, char *argv[], t_args *args)
{
	int	i;

	i = -1;
	args->n_philo = ft_atol(argv[1]);
	args->philo = malloc(args->n_philo * sizeof(t_philo));
	args->philo_thread = malloc(args->n_philo * sizeof(pthread_t));
	args->forks = malloc(args->n_philo * sizeof(pthread_mutex_t));
	args->is_dead = FALSE;
	if (argc == 6 && ft_atol(argv[5]) != 0)
		args->check_meals = TRUE;
	else
		args->check_meals = FALSE;
	pthread_mutex_init(&args->write_mut, NULL);
	pthread_mutex_init(&args->check_dead, NULL);
	while (++i < args->n_philo)
		pthread_mutex_init(&args->forks[i], NULL);
	pthread_mutex_init(&args->eating, NULL);
	args->start_time = get_start_time();
	args->argc = argc;
	initphilo(argv, args);
}

void	initphilo(char *argv[], t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->n_philo)
	{
		args->philo[i].t_to_die = ft_atol(argv[2]);
		args->philo[i].t_to_eat = ft_atol(argv[3]);
		args->philo[i].t_to_sleep = ft_atol(argv[4]);
		if (argv[5] != NULL)
			args->philo[i].n_times_to_eat = ft_atol(argv[5]);
		args->philo[i].id = i + 1;
		args->philo[i].t_last_meal = 0;
		args->philo[i].args = args;
		args->philo[i].t_cur_meal = 0;
		args->philo[i].left_fork = i;
		args->philo[i].right_fork = (i + 1) % args->n_philo;
		args->philo[i].full = FALSE;
	}
}
