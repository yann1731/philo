#include "../include/philosopher.h"

int	getms(t_philo *philo)
{
	long long	second;
	long long microsecond;
	int ms = 0;

	gettimeofday(&philo->current_time, NULL);
	second = philo->current_time.tv_sec - philo->args->start_time->tv_sec;
	microsecond = philo->current_time.tv_usec - philo->args->start_time->tv_usec;
	ms = second * 1000;
	ms += microsecond / 1000;
	return (ms);
}