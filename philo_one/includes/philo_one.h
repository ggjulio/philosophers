/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:32:23 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/06 21:34:44 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>

# include "color_shell.h"

#               include "libft.h"

typedef	enum	e_action
{
	Action_None,
	Action_Sleep,
	Action_Eat,
	Action_Think,
	Action_Died
}				t_action;

typedef struct	s_philo
{
	int				id;
	int				nb_meal;
	struct timeval	last_meal;
	char			*color;
	t_action		action;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}				t_philo;

typedef struct	s_simulation
{
	int				nb_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int 			nb_time_each_philosophers_must_eat;
	struct timeval	start_time;
	t_philo			**philos;
	pthread_mutex_t	*forks;
}				t_simulation;

/*
** simulation.c
*/
t_simulation	create_simulation(const int ac, const char **av);
void			destroy_simulation(t_simulation to_destroy);

/*
** run_simulation.c
*/
void			*philo_happy(void *philo);
void			run_simulation(void);

/*
** philo_action.c
*/
void			philo_sleep(t_philo *philo);
void			philo_eat(t_philo *philo);
void			philo_think(t_philo *philo);

/*
** helper_time.c
*/
void			usleep_ms(uint64_t ms);
uint64_t		get_ms_since_start(void);

/*
** philo.c
*/
t_philo			create_philo(int id, pthread_mutex_t *left_fork,
					pthread_mutex_t *right_fork);
t_philo*		malloc_philo(int id, pthread_mutex_t *left_fork,
					pthread_mutex_t *right_fork);
void			destroy_philo(t_philo to_destroy);
void			free_philo(t_philo *to_free);

extern t_simulation g_simu;

#endif
