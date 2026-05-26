/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dandrush <dandrush@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:11:54 by dandrush          #+#    #+#             */
/*   Updated: 2026/05/04 13:31:08 by dandrush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	const char		*sl;

	ch = (unsigned char)c;
	sl = NULL;
	while (1)
	{
		if ((unsigned char)*s == ch)
			sl = s;
		if (*s == '\0')
			break ;
		s++;
	}
	return ((char *)sl);
}
