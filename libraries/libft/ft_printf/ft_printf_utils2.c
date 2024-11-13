/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:05:43 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/05/30 14:38:30 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_div_num_base(long int number, int base)
{
	int	len;

	len = 0;
	if (number < 0)
	{
		number = -number;
		len++;
	}
	if (number == 0)
		return (1);
	while (number > 0)
	{
		number = number / base;
		len++;
	}
	return (len);
}

int	ft_puthex(unsigned int number, char variable)
{
	unsigned int	len;

	len = ft_div_num_base(number, 16);
	if (number == 0)
		return (ft_putchar_p('0'));
	if (number >= 16)
	{
		ft_puthex(number / 16, variable);
		ft_puthex(number % 16, variable);
	}
	else
	{
		if (number <= 9)
			ft_putchar_p(number + '0');
		else
		{
			if (variable == 'x')
				ft_putchar_p(number - 10 + 'a');
			else if (variable == 'X')
				ft_putchar_p(number - 10 + 'A');
		}
	}
	return (len);
}

static void	ft_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_ptr(num / 16);
		ft_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_p(num + '0');
		else
			ft_putchar_p(num - 10 + 'a');
	}
}

int	ft_putptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len += ft_putstr_p("(nil)");
	else
	{
		len += ft_putstr_p("0x");
		ft_ptr(ptr);
		len += ft_div_num_base(ptr, 16);
	}
	return (len);
}
