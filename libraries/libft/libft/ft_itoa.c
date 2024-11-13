/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:04:47 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/16 15:24:18 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*return_lenght(char *str, long long n)
{
	if (n > 9)
		str = return_lenght(str, n / 10);
	*str++ = (n % 10) + '0';
	*str = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	char	str[15];

	if (n < 0)
	{
		str[0] = '-';
		return_lenght(&str[1], (long long)n * -1);
	}
	else
		return_lenght(str, n);
	return (ft_substr(str, 0, ft_strlen(str)));
}

/* int	main(void)
{
	int		number;
	char	*result;

	number = 0;
	result = ft_itoa(number);
	printf("Number is: %i\nNumber after itoa: %s\n", number, result);
	free(result);
	return (0);
}
 */