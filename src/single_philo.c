/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:18:30 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/18 15:18:33 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

void	single_philo(t_philo *philo)
{
	pthread_create(&philo->args->philo_thread[0], NULL, &single_philo_act, (void *) philo);
}
