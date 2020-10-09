/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 23:33:42 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/09 23:32:04 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_atoi(const char *s)
{
	size_t	i;
	long	res;
	int		sign;

	i = -1;
	res = 0;
	sign = 1;
	while (ft_isspace(s[++i]))
		;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			sign = -1;
	while (ft_isdigit(s[i]))
		res = res * 10 + s[i++] - '0';
	return (res * sign);
}
