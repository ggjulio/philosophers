/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:24:56 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/12 06:06:17 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		usleep_ms(uint64_t ms)
{
	usleep(ms * 1000);
}

uint64_t	get_ms_since(struct timeval start)
{
	struct timeval	actual;
	struct timeval	diff;

	gettimeofday(&actual, NULL);
	diff.tv_sec = actual.tv_sec - start.tv_sec;
	diff.tv_usec = actual.tv_usec - start.tv_usec;
	return ((diff.tv_sec * (uint64_t)1000) + (diff.tv_usec / 1000));
}

uint64_t	get_ms_since_start(void)
{
	return (get_ms_since(g_simu.start_time));
}
