/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:37:51 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/05 10:00:15 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_simulation	create_simulation(const int ac, const char **av)
{
	t_simulation result;

	result.nb_philosophers = ft_atoi(av[1]);
	result.time_to_die = ft_atoi(av[2]);
	result.time_to_eat = ft_atoi(av[3]);
	result.time_to_sleep = ft_atoi(av[4]);
	result.nb_time_each_philosophers_must_eat = ac == 5 ? ft_atoi(av[5]) : -1;
	
	return (result);
}

void			destroy_simulation(t_simulation to_destroy)
{
	(void)to_destroy;
}

void			*philo_happy(void *philo)
{
	(void)philo;
	return (NULL);
}



void			run_simulation(void)
{
	t_philo		philos[g_simu.nb_philosophers];
	int i;
	int ret;

	i = -1;
	while (++i < g_simu.nb_philosophers)
	{
		create_philo(i);
		ret = pthread_create(&philos[i].thread, NULL, philo_happy, &philos[i]);
		if (ret != 0)
			ft_printf("Error : philo nb -> %d", i + 1);
	}
	while (42)
		;

	i = -1;
	while (++i < g_simu.nb_philosophers)
		pthread_join(&(philos[i].thread), NULL);
}
