/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dandrush <dandrush@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:13:56 by dandrush          #+#    #+#             */
/*   Updated: 2026/05/04 14:04:47 by dandrush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*sv1;
	unsigned char	*sv2;
	size_t			i;

	i = 0;
	sv1 = (unsigned char *)s1;
	sv2 = (unsigned char *)s2;
	while (i < n)
	{
		if (sv1[i] != sv2[i])
		{
			return ((int)(sv1[i] - sv2[i]));
		}
		i++;
	}
	return (0);
}
