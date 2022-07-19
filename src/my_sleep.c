/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:17:44 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/18 15:17:50 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

void	my_sleep(t_philo *philo, int time_to_wait)
{
	long long	current_time;
	long long	diff;

	current_time = get_ts(philo->args);
	while (1)
	{
		diff = get_ts(philo->args) - current_time;
		if (diff >= time_to_wait)
			break ;
		usleep(50);
	}
}
