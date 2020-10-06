/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:24:44 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/06 21:32:40 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_simulation	g_simu;

int		main(const int ac, const char **av)
{
	if (ac < 5 || ac > 6)
	{
		ft_printf("bad args bitch\n");
		return (0);
	}
	g_simu = create_simulation(ac, av);
	run_simulation();
	destroy_simulation(g_simu);
	return (0);
}
