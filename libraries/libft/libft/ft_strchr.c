/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:05:30 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/20 12:05:08 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = -1;
	while (str[++i] != (char)c && str[i])
		;
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}

/* int main()
{
	char *str = "Ola isto e um teste!";
	char c = 'i';
	char *result = ft_strchr(str, c);

	printf("String is: %s\nLetter is: %c\nResult is: %s", str, c, result);
	return (0);
} */
