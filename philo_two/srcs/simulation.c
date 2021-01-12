/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:37:51 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/12 04:29:33 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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
	i = -1;
	while (++i < result.nb_philosophers)
		result.philos[i] = malloc_philo(i);
	gettimeofday(&(result.start_time), NULL);
	sem_unlink(SEM_NAME);
	sem_unlink(SEM_NAME_LOCK);
	result.sem = sem_open(SEM_NAME, O_CREAT | O_RDWR, 0660,
								result.nb_philosophers);
	result.lock = sem_open(SEM_NAME_LOCK, O_CREAT | O_RDWR, 0660, 1);
	return (result);
}

void			destroy_simulation(t_simulation to_destroy)
{
	int i;

	i = -1;
	while (++i < to_destroy.nb_philosophers)
		free_philo(to_destroy.philos[i]);
	if (to_destroy.philos != NULL)
		free(to_destroy.philos);
	sem_close(to_destroy.sem);
	sem_unlink(SEM_NAME);
	sem_close(to_destroy.lock);
	sem_unlink(SEM_NAME_LOCK);
}
