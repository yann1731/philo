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