/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:37:51 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/04 18:00:59 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_simulation	create_simulation(const int ac, const char **av)
{
	t_simulation result;

	result.nb_philosophers = ft_atoi(av[1]);
	result.nb_philosophers = ft_atoi(av[2]);
	result.nb_philosophers = ft_atoi(av[3]);
	result.nb_philosophers = ft_atoi(av[4]);
	result.nb_philosophers = ac == 5 ? ft_atoi(av[5]) : -1;
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



void			run_simulation(t_simulation to_run)
{
	t_philo		philos[to_run.nb_philosophers];
	int i;
	int ret;

	i = -1;
	while (++i < to_run.nb_philosophers)
	{
		create_philo(i);
		ret = pthread_create(&philos[i].thread, NULL, philo_happy, &philos[i]);
		if (ret != 0)
			ft_printf("Error : philo nb -> %d", i + 1);
	}
	while (0)
	{
		
	}
	i = -1;
	while (++i < to_run.nb_philosophers)
		pthread_join(&(philos[i].thread[i]), NULL);
}
