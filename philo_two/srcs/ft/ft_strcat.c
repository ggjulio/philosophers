/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 23:34:17 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/09 23:33:36 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	char	*s;

	i = ft_strlen(dest);
	s = (char *)src;
	while (*s)
		dest[i++] = *s++;
	dest[i] = '\0';
	return (dest);
}
