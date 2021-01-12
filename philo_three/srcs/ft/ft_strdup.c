/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:23:46 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/12 06:06:05 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*res;

	if (!(res = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	i = -1;
	while (s[++i])
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}
