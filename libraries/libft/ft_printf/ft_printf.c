/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:08:21 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/05/30 13:20:19 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_format(va_list args, const char variable)
{
	int	print_len;

	print_len = 0;
	if (variable == 'c')
		print_len += ft_putchar_p(va_arg(args, int));
	else if (variable == 's')
		print_len += ft_putstr_p(va_arg(args, char *));
	else if (variable == 'd' || variable == 'i')
		print_len += ft_putnbr_p(va_arg(args, int));
	else if (variable == 'l')
		print_len += ft_putnbr_p(va_arg(args, long int));
	else if (variable == 'u')
		print_len += ft_putnbr_u(va_arg(args, unsigned int));
	else if (variable == 'x' || variable == 'X')
		print_len += ft_puthex(va_arg(args, unsigned int), variable);
	else if (variable == 'p')
		print_len += ft_putptr(va_arg(args, unsigned long));
	else if (variable == '%')
		print_len += ft_putchar_p('%');
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_len;
	va_list	args;

	if (!str)
		return (-1);
	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_format(args, str[i + 1]);
			i++;
		}
		else
			print_len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (print_len);
}
