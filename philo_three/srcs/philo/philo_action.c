/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:22:07 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/12 06:06:22 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	set_action(t_philo *philo, t_action action)
{
	if (philo->action != Action_Died && g_simu.running)
		philo->action = action;
}

void	philo_sleep(t_philo *philo)
{
	set_action(philo, Action_Sleep);
	print_message(philo, "is sleeping", 0);
	usleep_ms(g_simu.time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	sem_wait(g_simu.lock);
	sem_wait(g_simu.sem);
	print_message(philo, "has taken a fork", 0);
	sem_wait(g_simu.sem);
	print_message(philo, "has taken a fork", 0);
	sem_post(g_simu.lock);
	set_action(philo, Action_Eat);
	print_message(philo, "is eating", 0);
	usleep_ms(g_simu.time_to_eat);
	gettimeofday(&(philo->last_meal), NULL);
	philo->nb_meal++;
	sem_post(g_simu.sem);
	sem_post(g_simu.sem);
}

void	philo_think(t_philo *philo)
{
	set_action(philo, Action_Think);
	print_message(philo, "is thinking", 0);
}
