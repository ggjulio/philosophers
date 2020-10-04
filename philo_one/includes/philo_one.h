/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:32:23 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/04 18:14:26 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>


#               include "libft.h"

typedef	enum	e_action
{
	Action_None,
	Action_Sleep,
	Action_Eat,
	Action_Think
}				t_action;


typedef struct	s_philo
{
	int			id;
	t_action	action;
	pthread_t	thread;
	
}				t_philo;

typedef struct	s_simulation
{
	int			nb_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int 		nb_time_each_philosophers_must_eat;
	t_philo		*philos;
}				t_simulation;

t_simulation	create_simulation(const int ac, const char **av);
void			destroy_simulation(t_simulation to_destroy);
void			run_simulation(t_simulation to_run);

t_philo			create_philo(int id);
t_philo*		malloc_philo(int id);
void			destroy_philo(t_philo to_destroy);
void			free_philo(t_philo *to_free);

#endif
