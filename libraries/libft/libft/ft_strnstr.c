/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:53:51 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/18 15:59:48 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	size_t	i;
	size_t	needle_len;
	size_t	haystack_len;

	needle_len = ft_strlen(needle);
	if (size == 0 && (!haystack || !needle))
		return (NULL);
	if (needle_len == 0)
		return ((char *)haystack);
	haystack_len = -1;
	while (haystack[++haystack_len] && haystack_len < size)
	{
		i = -1;
		while (++i < needle_len && haystack[haystack_len + i] == needle[i]
			&& haystack_len + i < size)
			;
		if (i == needle_len)
			return ((char *)&haystack[haystack_len]);
	}
	return (NULL);
}

/* int	main(void)
{
	char	*haystack;
	char	*needle;
	size_t	size;
	char	*str;
	char	*result;

	haystack = "This is a haystack test message!";
	needle = "haystack";
	size = ft_strlen(haystack);
	printf("Haystack is: %s\nNeedle is: %s\nLenght is: %zu\n", haystack, needle,
		size);
	printf("Output is: %s\n", ft_strnstr(haystack, needle, size));
	return (0);
} */
