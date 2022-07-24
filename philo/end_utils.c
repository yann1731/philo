/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:09:38 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/19 10:09:40 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosopher.h"

void	end_philo(t_args *args)
{
	int	i;

	i = -1;
	while (args->is_dead == FALSE)
	{
		if (check_full(args) == TRUE)
			break ;
	}
	while (++i < args->n_philo)
		pthread_join(args->philo_thread[i], NULL);
	destroy_mutex(args);
	freeall(args);
}

void	freeall(t_args *args)
{
	free(args->philo_thread);
	free(args->philo);
	free(args->forks);
	free(args);
}

void	freeargs(t_args *args)
{
	free(args);
}

void	destroy_mutex(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->n_philo)
		pthread_mutex_destroy(&args->forks[i]);
	pthread_mutex_destroy(&args->check_dead);
	pthread_mutex_destroy(&args->write_mut);
	pthread_mutex_destroy(&args->eating);
}
