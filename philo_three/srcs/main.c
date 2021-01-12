/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:24:44 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/12 06:06:28 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

t_simulation	g_simu;

int		valid_input(const int ac, char **av)
{
	if ((ac == 5 || (ac == 6 && ft_isnumber(av[5])))
		&& ft_isnumber(av[1]) && ft_isnumber(av[2])
		&& ft_isnumber(av[3]) && ft_isnumber(av[4]))
	{
		if (ft_atoi(av[1]) <= 1)
			write(STDOUT_FILENO, "At least 2 philosophers...\n", 27);
		else
			return (1);
	}
	else
		write(STDOUT_FILENO, "Bad args\n", 9);
	return (0);
}

int		main(const int ac, const char **av)
{
	if (valid_input(ac, (char**)av))
	{
		g_simu = create_simulation(ac, av);
		run_simulation();
		destroy_simulation(g_simu);
	}
	return (0);
}
