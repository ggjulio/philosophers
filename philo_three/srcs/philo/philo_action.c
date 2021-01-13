/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:22:07 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/13 07:41:16 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*philo_happy(void *p_philo)
{
	t_philo *philo;

	philo = p_philo;
	while (42)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	philo_sleep(t_philo *philo)
{
	print_message(philo, "is sleeping");
	usleep_ms(g_simu.time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	sem_wait(g_simu.lock);
	sem_wait(g_simu.forks);
	print_message(philo, "has taken a fork");
	sem_wait(g_simu.forks);
	print_message(philo, "has taken a fork");
	sem_post(g_simu.lock);
	print_message(philo, "is eating");
	usleep_ms(g_simu.time_to_eat);
	gettimeofday(&(philo->last_meal), NULL);
	philo->nb_meal++;
	sem_post(g_simu.forks);
	sem_post(g_simu.forks);
}

void	philo_think(t_philo *philo)
{
	print_message(philo, "is thinking");
}
