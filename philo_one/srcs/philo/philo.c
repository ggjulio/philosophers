/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:31:42 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/06 21:35:46 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static char	*assign_color(void)
{
	static int	i = 0;
	const char	str[13][10] = {_LIGHT_RED, _LIGHT_GREEN, _LIGHT_YELLOW,
			_LIGHT_BLUE, _LIGHT_MAGENTA, _LIGHT_CYAN, _DARK_GREY, _CYAN,
			_MAGENTA, _BLUE, _YELLOW, _GREEN, _RED};

	if (i < 13)
		return (ft_strdup(str[i++]));	
	return (ft_strdup(_COLOR_DEFAULT));
}

t_philo		create_philo(int id, pthread_mutex_t *left_fork,
				pthread_mutex_t *right_fork)
{
	t_philo	result;

	memset(&result, 0, sizeof(t_philo));
	result.id = id;
	result.nb_meal = 0;
	result.color = assign_color();
	result.action = Action_None;
	result.left_fork = left_fork;
	result.right_fork = right_fork;
	gettimeofday(&(result.last_meal), NULL);
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
	if (to_destroy.color)
		free(to_destroy.color);
}

void		free_philo(t_philo *to_free)
{
	destroy_philo(*to_free);
	free(to_free);
}
