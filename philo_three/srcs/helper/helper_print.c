/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:30:00 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/12 06:06:14 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static int	putnbru(char *dest, unsigned int n)
{
	uint8_t i;

	i = 0;
	if (n >= 10)
		i = putnbru(dest, n / 10);
	dest[i] = n % 10 + '0';
	return (i + 1);
}

static void	putnbr(char *dest, int n)
{
	dest[putnbru(dest, n)] = '\0';
}

static void	do_padding(char *dest, uint64_t n, int pad_size)
{
	int size;
	int i;

	size = 0;
	while ((n = n / 10))
		size++;
	i = 0;
	while (i < pad_size - size - 1)
		dest[i++] = ' ';
	dest[i] = '\0';
}

void		print_message(t_philo *philo, char *message, int force)
{
	char		buffer[60];
	uint64_t	ms;

	if (!g_simu.running && !force)
		return ;
	ms = get_ms_since_start();
	do_padding(buffer, ms, 7);
	putnbr(buffer + ft_strlen(buffer), ms);
	ft_strcat(buffer, philo->color);
	ft_strcat(buffer, " ");
	do_padding(buffer + ft_strlen(buffer), philo->id + 1, 3);
	putnbr(buffer + ft_strlen(buffer), philo->id + 1);
	ft_strcat(buffer, " ");
	ft_strcat(buffer, message);
	ft_strcat(buffer, "\n");
	ft_strcat(buffer, _R);
	write(STDOUT_FILENO, buffer, ft_strlen(buffer));
}

void		print_summary(void)
{
	int			i;
	char		buffer[60];
	const char	summary[] = "\n\nSummary :\n\n";
	const char	*emoji[5] = {EMOJI_NULL,
				EMOJI_SLEEPING, EMOJI_EATING, EMOJI_THINKING, EMOJI_DEAD};

	i = -1;
	write(STDOUT_FILENO, summary, ft_strlen(summary));
	while (++i < g_simu.nb_philosophers)
	{
		buffer[0] = '\0';
		ft_strcat(buffer, emoji[g_simu.philos[i]->action]);
		ft_strcat(buffer, "  ");
		ft_strcat(buffer, g_simu.philos[i]->color);
		do_padding(buffer + ft_strlen(buffer), g_simu.philos[i]->id + 1, 3);
		putnbr(buffer + ft_strlen(buffer), g_simu.philos[i]->id + 1);
		ft_strcat(buffer, " -> meals : ");
		putnbr(buffer + ft_strlen(buffer), g_simu.philos[i]->nb_meal);
		ft_strcat(buffer, "\n");
		ft_strcat(buffer, _R);
		write(STDOUT_FILENO, buffer, ft_strlen(buffer));
	}
}
