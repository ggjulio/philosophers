/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:22:07 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/06 15:55:59 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_sleep(t_philo *philo)
{
	philo->action = Action_Sleep;
	ft_printf("% 4llu %s%d is sleeping%s\n", get_ms_since_start(), philo->color, philo->id + 1, _R);
	usleep_ms(g_simu.time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	philo->action = Action_Eat;
	ft_printf("% 4llu %s%d is eating%s\n", get_ms_since_start(), philo->color, philo->id + 1, _R);
	usleep_ms(g_simu.time_to_eat);
	philo->nb_meal++;
}

void	philo_think(t_philo *philo)
{
	philo->action = Action_Think;
	ft_printf("%llu %s%d is thinking%s\n", get_ms_since_start(), philo->color, philo->id + 1, _R);

}