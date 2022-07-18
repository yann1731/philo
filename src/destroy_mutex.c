/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:16:06 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/18 15:16:09 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

void	destroy_mutex(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->n_philo)
		pthread_mutex_destroy(&args->forks[i]);
	pthread_mutex_destroy(&args->check_dead);
	pthread_mutex_destroy(&args->write_mut);
}
