/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:34:49 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/06 21:31:46 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		exit_not_yet(void)
{
	int i;

	i = -1;
	while (++i < g_simu.nb_philosophers)
	{
		if (g_simu.philos[i]->action == Action_Died)
			return (0);
		if (g_simu.nb_time_each_philosophers_must_eat == -1)
			return (1);
		if (g_simu.philos[i]->nb_meal < g_simu.nb_time_each_philosophers_must_eat)
			return (1);
	}
	return (0);
}



void			*philo_happy(void *p_philo)
{
	t_philo *philo;

	philo = p_philo;
	while (exit_not_yet())
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void			print_summary()
{
	int i;

	i = -1;
	ft_printf("\n\nSummary :\n\n");
	while (++i < g_simu.nb_philosophers)
	{
		ft_printf("philo %d -> meals : %d\n", g_simu.philos[i]->id + 1,  g_simu.philos[i]->nb_meal);
	}
}

void			update_dead_philosophers(void)
{
	int i;

	i = -1;
	while (++i < g_simu.nb_philosophers)
	{
		if (g_simu.time_to_die)
			g_simu.philos[i]->action = Action_Died;
	}
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
	while (exit_not_yet())
		update_dead_philosophers();
	i = -1;
	while (++i < g_simu.nb_philosophers)
		pthread_join(g_simu.philos[i]->thread, NULL);
	print_summary();
}
