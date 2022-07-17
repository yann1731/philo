#include "../include/philosopher.h"

long long	get_ts(t_philo *philo)
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec + (current_time.tv_usec / 1000)) - philo->args->start_time);
}