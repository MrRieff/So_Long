/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:32 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/15 17:51:12 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	if (size == 0)
		return (0);
	while (size > i)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/* int main()
{
	char *str1 = "Hello this bs a test!";
	char *str2 = "Hello this as a test!";
	int size = ft_strlen(str2);

	printf("String 1 is: %s\nString 2 is: %s\nSize is: %i\n", str1, str2, size);
	printf("Result is: %i\n", ft_memcmp(str1, str2, size));
	return (0);
} */
