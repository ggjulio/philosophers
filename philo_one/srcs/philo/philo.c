/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:31:42 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/05 18:38:22 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_philo		create_philo(int id, pthread_mutex_t *left_fork,
				pthread_mutex_t *right_fork)
{
	t_philo	result;

	memset(&result, 0, sizeof(t_philo));
	result.id = id;
	result.nb_meal = 0;
	result.action = Action_None;
	result.left_fork = left_fork;
	result.right_fork = right_fork;
	return (result);
}

t_philo		*malloc_philo(int id, pthread_mutex_t *left_fork,
				pthread_mutex_t *right_fork)
{
	t_philo *result;

	if (!(result = malloc(sizeof(t_philo))))
		return (NULL);
	*result = create_philo(id, left_fork, right_fork);
	return (result);
}

void		destroy_philo(t_philo to_destroy)
{
	(void)to_destroy;
}

void		free_philo(t_philo *to_free)
{
	destroy_philo(*to_free);
	free(to_free);
}
