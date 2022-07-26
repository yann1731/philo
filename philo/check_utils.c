/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:09:27 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/19 10:09:29 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosopher.h"

int	check_full(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->n_philo)
	{
		if (args->philo[i].full == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

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

void	checkdeath(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->check_dead);
	if ((get_ts(philo->args) - philo->t_last_meal) >= philo->t_to_die
		&& philo->args->is_dead == FALSE && philo->full == FALSE)
	{
		philo->args->is_dead = TRUE;
		printf("%lld %d has died\n", get_ts(philo->args), philo->id);
	}
	pthread_mutex_unlock(&philo->args->check_dead);
}

void	check(int argc, char *argv[], t_args *args)
{
	if (checkargsnum(argc) == 1)
		args->error = TRUE;
	if (check_validity(argv) == 1)
		args->error = TRUE;
	if (checkintlimit(argv) == 1)
		args->error = TRUE;
}

int	checkintlimit(char *argv[])
{
	if (ft_atol(argv[1]) > INT_MAX || ft_atol(argv[2]) > INT_MAX
		|| ft_atol(argv[3]) > INT_MAX || ft_atol(argv[4]) > INT_MAX)
	{
		dprintf(STDERR_FILENO, "Argument needs to be lower than %d\n", INT_MAX);
		return (1);
	}
	if (argv[5])
		if (ft_atol(argv[5]) > INT_MAX)
		{
			dprintf(STDERR_FILENO, "Argument needs to be lower than %d\n", INT_MAX);
			return (1);
		}
	return (0);
}
