/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:24:44 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/05 09:53:24 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_simulation	g_simu;

int main(const int ac, const char **av)
{
	t_simulation simulation;

	if (ac < 4 || ac > 5)
		return (0);
	g_simu = create_simulation(ac, av);
	run_simulation();
	destroy_simulation(simulation);
	return (0);
}
