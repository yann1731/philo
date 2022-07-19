#include "../include/philosopher.h"

int check_full(t_args *args)
{
    int i;

    i = -1;
    while (++i < args->n_philo)
    {
        if (args->philo[i].full == FALSE)
            return (FALSE);
    }
    return (TRUE);
}