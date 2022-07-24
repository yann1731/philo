/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:17:31 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/18 15:17:37 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosopher.h"

int	main(int argc, char *argv[])
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	check(argc, argv, args);
	if (args->error == FALSE)
	{
		initargs(argc, argv, args);
		if (args->n_philo == 1)
			single_philo(args->philo);
		else
			create_philos(args);
		check_philo_status(args);
		end_philo(args);
	}
	else
	{
		freeargs(args);
		return (1);
	}
	return (0);
}
