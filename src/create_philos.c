/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:15:56 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/18 15:15:59 by yannickst        ###   ########.fr       */
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
