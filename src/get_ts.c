#include "../include/philosopher.h"

long long	get_ts(t_args *args)
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return (((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000)) - args->start_time);
}