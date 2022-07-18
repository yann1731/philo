#include "../include/philosopher.h"

void	check_philo_status(t_args *args)
{
	int	i;

	i = 0;
	while (args->is_dead == FALSE)
	{
		checkdeath(&args->philo[i]);
		if (i == args->n_philo - 1)
			i = -1;
		i++;
	}
}