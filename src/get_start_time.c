/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:16:49 by yannickst         #+#    #+#             */
/*   Updated: 2022/07/18 15:16:52 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

long long	get_start_time(void)
{
	struct timeval starttime;

	gettimeofday(&starttime, NULL);
	return ((starttime.tv_sec * 1000) + (starttime.tv_usec / 1000));
}
