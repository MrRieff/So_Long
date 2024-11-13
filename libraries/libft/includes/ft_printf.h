/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:06:31 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/05/30 14:39:22 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#include "libft.h"

int		ft_putstr_p(char *str);
int		ft_putnbr_p(long long int number);
int		ft_putnbr_u(unsigned long long int number);
int		ft_puthex(unsigned int number, char variable);
int		ft_putptr(unsigned long long ptr);
int		ft_format(va_list args, const char variable);
int		ft_printf(const char *str, ...);
int		ft_div_num_base(long int number, int base);
int		ft_putchar_p(char c);

#endif
