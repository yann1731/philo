/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkdeath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:15:25 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/18 15:15:28 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

void	checkdeath(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->check_dead);
	if ((get_ts(philo->args) - philo->t_last_meal) >= philo->t_to_die && philo->args->is_dead == FALSE)
	{
		philo->args->is_dead = TRUE;
		printf("%lld %d has died\n", get_ts(philo->args), philo->id);
	}
	pthread_mutex_unlock(&philo->args->check_dead);
}
