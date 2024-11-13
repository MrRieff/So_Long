/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:13:16 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/20 13:13:44 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		else
			i--;
	}
	return (0);
}
/* int	main(void)
{
	char	*str;
	char	c;
	char	*result;

	str = "Ola isto e um teste!";
	c = 'o';
	result = ft_strrchr(str, c);
	printf("Original string is: %s\nCharacter is: %c\nResult is: %s", str, c,
		result);
	return (0);
} */
