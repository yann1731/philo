/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:10:11 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/19 10:10:14 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (*str == '\t' || *str == ' ' || *str == '\n'
		|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (!(*str <= '9' && *str >= '0'))
		return (0);
	while (*str <= '9' && *str >= '0')
	{
		num = num * 10;
		num += *str - 48;
		str++;
	}
	return (num * sign);
}

long long	get_start_time(void)
{
	struct timeval	starttime;

	gettimeofday(&starttime, NULL);
	return ((starttime.tv_sec * 1000) + (starttime.tv_usec / 1000));
}

long long	get_ts(t_args *args)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (((current_time.tv_sec * 1000)
			+ (current_time.tv_usec / 1000)) - args->start_time);
}

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

void	print(t_philo *philo, char *action)
{
	if (philo->args->is_dead == FALSE)
	{
		pthread_mutex_lock(&(philo->args->write_mut));
		printf("%lld %d %s\n", get_ts(philo->args), philo->id, action);
		pthread_mutex_unlock(&(philo->args->write_mut));
	}
}
