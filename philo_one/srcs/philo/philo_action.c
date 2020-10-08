/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:22:07 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/08 19:41:54 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_sleep(t_philo *philo)
{
	philo->action = Action_Sleep;
	if (!g_simu.died)
		print_message(philo, "is sleeping");
	// ft_printf("%4lu %s%d is sleeping%s\n", get_ms_since_start(), philo->color, philo->id + 1, _R);

	usleep_ms(g_simu.time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (!g_simu.died)
		print_message(philo, "has taken a fork");
	// ft_printf("%4lu %s%d has taken a fork%s\n", get_ms_since_start(), philo->color, philo->id + 1, _R);
	pthread_mutex_lock(philo->left_fork);
	if (!g_simu.died)
		print_message(philo, "has taken a fork");
	// ft_printf("%4lu %s%d has taken a fork%s\n", get_ms_since_start(), philo->color, philo->id + 1, _R);

	philo->action = Action_Eat;
	if (!g_simu.died)
		print_message(philo, "is eating");
		// ft_printf("%4lu %s%d is eating%s\n", get_ms_since_start(), philo->color, philo->id + 1, _R);
	usleep_ms(g_simu.time_to_eat);
	gettimeofday(&(philo->last_meal), NULL);
	philo->nb_meal++;

	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_think(t_philo *philo)
{
	philo->action = Action_Think;
	if (!g_simu.died)
		print_message(philo, "is thinking");
		// ft_printf("%4lu %s%d is thinking%s\n", get_ms_since_start(), philo->color, philo->id + 1, _R);
}
