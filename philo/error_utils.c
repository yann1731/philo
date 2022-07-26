/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:09:49 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/19 10:09:52 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosopher.h"

int	check_validity(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (argv[++i])
	{
		while (argv[i][++j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			{
				write(2, "Must enter only positive numbers as arguments\n", 46);
				return (1);
			}
		}
		j = -1;
	}
	if (ft_atol(argv[1]) == 0)
	{
		dprintf(STDERR_FILENO, "Must enter more than one philosopher\n");
		return (1);
	}
	return (0);
}

int	checkargsnum(int argc)
{
	if (argc < 5 || argc > 6)
	{
		write(STDERR_FILENO, "Not the right number of arguments\n", 34);
		return (1);
	}
	return (0);
}
