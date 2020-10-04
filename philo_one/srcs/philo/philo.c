/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:31:42 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/04 18:14:15 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_philo			create_philo(int id)
{
	t_philo result;

	memset(&result, 0, sizeof(t_philo));
	result.id = id;
	result.action = Action_None;
	return (result);
}
t_philo*		malloc_philo(int id)
{
	t_philo *result;

	if (!(malloc(sizeof(t_philo))))
		return (NULL);
	*result = create_philo(id);
	return (result);
}

void			destroy_philo(t_philo to_destroy)
{
	(void)to_destroy;
}

void			free_philo(t_philo *to_free)
{
	destroy_philo(*to_free);
	free(to_free);
}
