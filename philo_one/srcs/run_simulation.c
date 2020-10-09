/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:34:49 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/09 16:47:39 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"


int		exit_not_yet(void)
{
	int i;

	if (g_simu.running == 0)
		return (g_simu.running);
	if (g_simu.nb_time_each_philosophers_must_eat == -1)
		return (1);
	i = -1;
	while (++i < g_simu.nb_philosophers)
	{
		if (g_simu.philos[i]->nb_meal < g_simu.nb_time_each_philosophers_must_eat)
			return (1);
	}
	return (0);
}

void			*philo_happy(void *p_philo)
{
	t_philo *philo;

	philo = p_philo;
	while (g_simu.running)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void			update_dead_philosophers(void)
{
	int i;

	i = -1;
	while (++i < g_simu.nb_philosophers)
	{
		if (get_ms_since(g_simu.philos[i]->last_meal) > (uint64_t)g_simu.time_to_die)
		{
			g_simu.running = 0;
			g_simu.philos[i]->action = Action_Died;
			print_message(g_simu.philos[i], "died");
		}
	}
	usleep(1);
}

void			run_simulation(void)
{
	int i;
	int ret;

	g_simu.running = 1;

	i = 0;
	while (i < g_simu.nb_philosophers)
	{
		ret = pthread_create(&g_simu.philos[i]->thread, NULL, philo_happy, g_simu.philos[i]);
		if (ret != 0)
			ft_printf("Error : philo nb -> %d", i + 1);
		i += 2;
	}
	usleep_ms(1);
	i = 1;
	while (i < g_simu.nb_philosophers)
	{
		ret = pthread_create(&g_simu.philos[i]->thread, NULL, philo_happy, g_simu.philos[i]);
		if (ret != 0)
			ft_printf("Error : philo nb -> %d", i + 1);
		i += 2;
	}

	while ((g_simu.running = exit_not_yet()))
		update_dead_philosophers();
	i = -1;
	while (++i < g_simu.nb_philosophers)
		pthread_join(g_simu.philos[i]->thread, NULL);
	print_summary();
}
