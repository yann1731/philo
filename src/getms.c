#include "../include/philosopher.h"

int	getms(t_philo *philo)
{
	int second;
	int microsecond;
	int ms;

	gettimeofday(&philo->current_time, NULL);
	//printf("current time sec: %ld\n", philo->current_time.tv_sec);
	//printf("start time sec: %ld\n", philo->start_time.tv_sec);
	second = philo->current_time.tv_sec - philo->start_time.tv_sec;
	//printf("second: %d\n", second);
	microsecond = philo->current_time.tv_usec - philo->start_time.tv_usec;
	//printf("microsecond: %d\n", microsecond);
	ms = second * 1000;
	ms += microsecond / 1000;
	return (ms);
}