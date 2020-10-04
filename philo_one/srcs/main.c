/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:24:44 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/04 17:02:14 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int main(const int ac, const char **av)
{
	t_simulation simulation;
	
	if (ac < 4 || ac > 5)
		return (0);
	simulation = create_simulation(ac, av);

	run_simulation(simulation);

	destroy_simulation(simulation);
	return (0);
}
