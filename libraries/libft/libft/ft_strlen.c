/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:42:17 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/16 19:39:49 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

/* int main()
{
	char *str = "This is a test string!";
	int result = ft_strlen(str);

	printf("String is: %s\nString lenght: %i\n", str, result);
	return (0);
} */
