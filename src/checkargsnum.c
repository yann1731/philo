/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargsnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:15:15 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/18 15:15:18 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

void	checkargsnum(int argc)
{
	if (argc < 5 || argc > 6)
	{
		write(STDERR_FILENO, "Not the right number of arguments", 33);
		exit(1);
	}
}
