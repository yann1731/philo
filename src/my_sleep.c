#include "../include/philosopher.h"

void	my_sleep(t_philo *philo, int time_to_wait)
{
	long long	current_time;
	long long	diff;

	current_time = get_ts(philo->args);
	while (1)
	{
		diff = get_ts(philo->args) - current_time;
		if (diff >= time_to_wait)
			break;
		usleep(50);
	}
}