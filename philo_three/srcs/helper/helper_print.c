/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:30:00 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/13 07:52:19 by juligonz         ###   ########.fr       */
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

void		print_message(t_philo *philo, char *message)
{
	char		buffer[60];
	uint64_t	ms;

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
