#include "../include/philosopher.h"

long long	get_start_time(void)
{
	struct timeval starttime;

	gettimeofday(&starttime, NULL);
	return (starttime.tv_sec + (starttime.tv_usec / 1000));
}