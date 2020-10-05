/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:34:49 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/05 18:46:50 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			*philo_happy(void *p_philo)
{
	t_philo *philo;

	philo = p_philo;
	while (42)
	{
		ft_printf("%d\n", philo->id);
	}
	return (NULL);
}



void			run_simulation(void)
{
	int i;
	int ret;

	i = -1;
	while (++i < g_simu.nb_philosophers)
	{
		ret = pthread_create(&g_simu.philos[i]->thread, NULL, philo_happy, g_simu.philos[i]);
		if (ret != 0)
			ft_printf("Error : philo nb -> %d", i + 1);
	}
	while (42)
		;

	i = -1;
	// while (++i < g_simu.nb_philosophers)
	// 	pthread_join(g_simu.philos[i]->thread, NULL);
}
