/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:37:51 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/09 19:38:52 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_simulation	create_simulation(const int ac, const char **av)
{
	t_simulation	result;
	int				i;

	result.nb_philosophers = ft_atoi(av[1]);
	result.time_to_die = ft_atoi(av[2]);
	result.time_to_eat = ft_atoi(av[3]);
	result.time_to_sleep = ft_atoi(av[4]);
	result.nb_time_each_philosophers_must_eat = ac == 6 ? ft_atoi(av[5]) : -1;
	if (!(result.philos = malloc(sizeof(t_philo *) * result.nb_philosophers)))
		result.philos = NULL;
	if (!(result.forks =
		malloc(sizeof(pthread_mutex_t) * result.nb_philosophers)))
		result.forks = NULL;
	i = -1;
	while (++i < result.nb_philosophers)
	{
		pthread_mutex_init(&result.forks[i], NULL);
		result.philos[i] =
	malloc_philo(i, i > 0 ? &result.forks[i - 1] : NULL, &result.forks[i]);
	}
	result.philos[0]->left_fork =
		result.philos[result.nb_philosophers - 1]->right_fork;
	gettimeofday(&(result.start_time), NULL);
	return (result);
}

void			destroy_simulation(t_simulation to_destroy)
{
	int i;

	i = -1;
	while (++i < to_destroy.nb_philosophers)
	{
		free_philo(to_destroy.philos[i]);
		pthread_mutex_destroy(&to_destroy.forks[i]);
	}
	if (to_destroy.philos != NULL)
		free(to_destroy.philos);
	if (to_destroy.forks != NULL)
		free(to_destroy.forks);
}
