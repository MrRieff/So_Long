/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:36:04 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/16 18:53:52 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	if (n == 0)
		return (0);
	while (++i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	}
	return (0);
}
/* int main()
{
	size_t size = 6;
	char *s1 = "test\200";
	char *s2 = "test\06";
	int result = ft_strncmp(s1, s2, size);

	printf("S1 is: %s\nS2 is: %s\nSize is: %zu\nResult is: %i\n", s1, s2, size,
		result);
	return (0);
} */
