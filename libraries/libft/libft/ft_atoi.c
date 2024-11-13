/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:15:39 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/15 18:21:16 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	i;
	int		result;

	i = -1;
	sign = 1;
	result = 0;
	while ((str[++i] >= 9 && str[i] <= 13) || str[i] == 32)
		;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = ((result * 10) + (str[i] - '0'));
		i++;
	}
	return (result * sign);
}
