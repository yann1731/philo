/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:10:27 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/19 10:10:30 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

void	create_philos(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->n_philo)
		pthread_create(&args->philo_thread[i], NULL,
			&philo_act, (void *) &args->philo[i]);
}

void	*single_philo_act(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	pthread_mutex_lock(&philo->args->forks[philo->left_fork]);
	print(philo, "has taken a fork");
	philo->t_last_meal = get_ts(philo->args);
	my_sleep(philo, philo->t_to_die);
	pthread_mutex_unlock(&philo->args->forks[philo->left_fork]);
	return (NULL);
}

void	single_philo(t_philo *philo)
{
	pthread_create(&philo->args->philo_thread[0], NULL,
		&single_philo_act, (void *) philo);
}
