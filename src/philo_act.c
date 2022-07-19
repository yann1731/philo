/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:18:03 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/18 15:18:06 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

void	eat(t_philo *philo)
{
	if (philo->args->is_dead == FALSE)
	{
		pthread_mutex_lock(&philo->args->forks[philo->left_fork]);
		print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->args->forks[philo->right_fork]);
		print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->args->eating);
		print(philo, "is eating");
		philo->t_last_meal = get_ts(philo->args);
		philo->n_meals_eaten++;
		pthread_mutex_unlock(&philo->args->eating);
		my_sleep(philo, philo->t_to_eat);
		pthread_mutex_unlock(&philo->args->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->args->forks[philo->right_fork]);
	}
}

void	think(t_philo *philo)
{
	if (philo->args->is_dead == FALSE)
	{
		print(philo, "is thinking");
	}
}

void	f_sleep(t_philo *philo)
{
	if (philo->args->is_dead == FALSE)
	{
		print(philo, "is sleeping");
		my_sleep(philo, philo->t_to_sleep);
	}
}

void	*philo_act(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		usleep(150);
	while (philo->args->is_dead == FALSE)
	{
		if (philo->args->is_dead == TRUE)
			break ;
		if (philo->args->check_meals == TRUE && philo->n_meals_eaten == philo->n_times_to_eat)
		{
			philo->full = TRUE;
			break ;
		}
		eat(philo);
		think(philo);
		f_sleep(philo);
	}
	return (NULL);
}
