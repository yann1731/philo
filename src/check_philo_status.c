/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:14:44 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/18 15:14:49 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

void	check_philo_status(t_args *args)
{
	int	i;

	i = 0;
	while (args->is_dead == FALSE)
	{
		checkdeath(&args->philo[i]);
		if (check_full(args) == TRUE)
		{
			printf("All philosophers are full\n");
			break ;
		}
		if (i == args->n_philo - 1)
			i = -1;
		i++;
	}
}
