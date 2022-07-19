/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:14:16 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/18 15:14:21 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

void	check(int argc, char *argv[], t_args *args)
{
	if (checkargsnum(argc) == 1)
		args->error = TRUE;
	if (check_validity(argv) == 1)
		args->error = TRUE;
}
