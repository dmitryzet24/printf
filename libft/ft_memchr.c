/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dandrush <dandrush@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:38:44 by dandrush          #+#    #+#             */
/*   Updated: 2026/05/04 13:30:20 by dandrush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// The  memchr()  function  scans  the  initial n bytes of the memory area
// pointed to by s for the first instance of c.
// Both c and the  bytes  of
// the memory area pointed to by s are interpreted as unsigned char.

void	*ft_memchr(const void *s, int c, size_t n)

{
	size_t			nv;
	unsigned char	cv;
	unsigned char	*sv;

	sv = (unsigned char *)s;
	cv = (unsigned char)c;
	nv = 0;
	while (nv < n)
	{
		if (sv[nv] == cv)
			return ((void *)(sv + nv));
		nv++;
	}
	return (NULL);
}
