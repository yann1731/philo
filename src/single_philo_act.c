/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_philo_act.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:18:47 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/18 15:18:50 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

void	*single_philo_act(void	*arg)
{
	t_philo *philo;
	philo = (t_philo *) arg;
	pthread_mutex_lock(&philo->args->forks[philo->left_fork]);
	print(philo, "has taken a fork");
	philo->t_last_meal = get_ts(philo->args);
	my_sleep(philo, philo->t_to_die);
	pthread_mutex_unlock(&philo->args->forks[philo->left_fork]);
	return (NULL);
}
