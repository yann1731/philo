/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:18:16 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/18 15:18:19 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

void	print(t_philo *philo, char *action)
{
	if (philo->args->is_dead == FALSE)
	{
		pthread_mutex_lock(&(philo->args->write_mut));
		printf("%lld %d %s\n", get_ts(philo->args), philo->id, action);
		pthread_mutex_unlock(&(philo->args->write_mut));
	}
}
