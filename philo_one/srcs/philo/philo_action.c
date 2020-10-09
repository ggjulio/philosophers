/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:22:07 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/09 17:07:25 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	set_action(t_philo *philo, t_action action)
{
	if (philo->action != Action_Died)
	// if (g_simu.running)
		philo->action = action;
}

void	philo_sleep(t_philo *philo)
{
	// philo->action = Action_Sleep;
	set_action(philo, Action_Sleep);
	print_message(philo, "is sleeping");
	usleep_ms(g_simu.time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, "has taken a fork");
	// philo->action = Action_Eat;
	set_action(philo, Action_Eat);

	print_message(philo, "is eating");
	usleep_ms(g_simu.time_to_eat);
	gettimeofday(&(philo->last_meal), NULL);
	philo->nb_meal++;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_think(t_philo *philo)
{
	// philo->action = Action_Think;
	set_action(philo, Action_Think);
	print_message(philo, "is thinking");
}
