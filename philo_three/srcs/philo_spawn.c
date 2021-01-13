/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_spawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 08:32:12 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/13 08:35:35 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	post_nb_meals_reached(int id)
{
	static int already_post = 0;

	if (already_post)
		return ;
	if (g_simu.nb_time_each_philosophers_must_eat == -1)
		return ;
	if (g_simu.philos[id]->nb_meal < g_simu.nb_time_each_philosophers_must_eat)
		return ;
	sem_post(g_simu.meals_done);
	already_post = 1;
}

static void	post_dead(int id)
{
	if (
	get_ms_since(g_simu.philos[id]->last_meal) > (uint64_t)g_simu.time_to_die)
	{
		print_message(g_simu.philos[id], "died");
		sem_post(g_simu.someone_died);
		g_simu.running = 0;
	}
}

void		spawn_philo(int id)
{
	g_simu.philos[id]->pid = fork();
	if (g_simu.philos[id]->pid == 0)
	{
		pthread_create(&g_simu.philos[id]->thread,
			NULL, philo_happy, g_simu.philos[id]);
		pthread_detach(g_simu.philos[id]->thread);
		while (g_simu.running)
		{
			post_nb_meals_reached(id);
			post_dead(id);
			usleep_ms(1);
		}
		exit(0);
	}
}
