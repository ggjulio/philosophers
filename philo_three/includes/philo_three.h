/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:32:23 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/13 07:41:30 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdint.h>
# include <fcntl.h>
# include <semaphore.h>
# include <signal.h>

# include "color_shell.h"

# define SEM_NAME			"/sem_philo_three_forks"
# define SEM_NAME_LOCK		"/sem_philo_three_lock"
# define SEM_NAME_DIED		"/sem_philo_three_died"
# define SEM_NAME_MEALS		"/sem_philo_three_meals"

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
	pthread_t		thread;
	pid_t			pid;
}				t_philo;

typedef struct	s_simulation
{
	int				running;
	int				nb_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_time_each_philosophers_must_eat;
	struct timeval	start_time;
	t_philo			**philos;
	sem_t			*forks;
	sem_t			*lock;
	sem_t			*someone_died;
	sem_t			*meals_done;
}				t_simulation;

/*
** simulation.c
*/
t_simulation	create_simulation(const int ac, const char **av);
void			destroy_simulation(t_simulation to_destroy);

/*
** run_simulation.c
*/
void			run_simulation(void);

/*
** philo.c
*/
t_philo			create_philo(int id);
t_philo			*malloc_philo(int id);
void			destroy_philo(t_philo to_destroy);
void			free_philo(t_philo *to_free);

/*
** philo_action.c
*/
void			*philo_happy(void *philo);
void			philo_sleep(t_philo *philo);
void			philo_eat(t_philo *philo);
void			philo_think(t_philo *philo);

/*
** helper_time.c
*/
void			usleep_ms(uint64_t ms);
uint64_t		get_ms_since(struct timeval start);
uint64_t		get_ms_since_start(void);

/*
** helper_print.c
*/
void			print_message(t_philo *philo, char *message);

/*
** ft
*/
char			*ft_strcat(char *dest, const char *src);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *s);
int				ft_isdigit(int c);
int				ft_isnumber(char *s);
int				ft_isspace(int c);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strdup(const char *s);

extern t_simulation g_simu;

#endif
