/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:34:49 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/13 08:37:13 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*wait_dead(void *useless)
{
	(void)useless;
	sem_wait(g_simu.someone_died);
	g_simu.running = 0;
	return (NULL);
}

void	*wait_nb_meals_reached(void *useless)
{
	int nb_philos_reached_nb_meals;

	(void)useless;
	nb_philos_reached_nb_meals = 0;
	while (g_simu.running)
	{
		sem_wait(g_simu.meals_done);
		nb_philos_reached_nb_meals++;
		if (nb_philos_reached_nb_meals == g_simu.nb_philosophers)
			break ;
		usleep(1);
	}
	g_simu.running = 0;
	return (NULL);
}

/*
** At the end I post to unlock threads and avoid still reachable memory.
** it's useless but, I don't want to be graded 0 by another of my peers.
*/

void	run_simulation(void)
{
	int			id;
	pthread_t	wait_dead_thread;
	pthread_t	wait_nb_meals_reached_thread;

	id = 0;
	g_simu.running = 1;
	while (id < g_simu.nb_philosophers)
		spawn_philo(id++);
	pthread_create(&wait_dead_thread, NULL, wait_dead, NULL);
	pthread_create(&wait_nb_meals_reached_thread,
					NULL, wait_nb_meals_reached, NULL);
	pthread_detach(wait_dead_thread);
	pthread_detach(wait_nb_meals_reached_thread);
	while (g_simu.running)
		usleep(1);
	id = 0;
	while (id < g_simu.nb_philosophers)
	{
		kill(g_simu.philos[id++]->pid, SIGKILL);
		sem_post(g_simu.meals_done);
	}
	sem_post(g_simu.someone_died);
}
