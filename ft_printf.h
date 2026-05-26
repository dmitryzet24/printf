/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dandrush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:35:02 by dandrush          #+#    #+#             */
/*   Updated: 2026/05/26 16:09:45 by dandrush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_putunsigned(unsigned int n);
int	ft_puthex(uintptr_t n, char format);
int	ft_putptr(uintptr_t ptr);

#endif
