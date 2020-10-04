/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:37:51 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/04 17:01:55 by juligonz         ###   ########.fr       */
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

void			run_simulation(t_simulation to_run)
{
		
}
