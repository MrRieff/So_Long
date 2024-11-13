/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:00:55 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/23 15:03:27 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = -1;
	if (size == 0)
		return (ft_strlen(src));
	if (size > 0)
	{
		while (src[++i] && i < (size - 1))
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/* int main()
{
	char *src = "This is a source message!";
	char dst[35] = "This will be overriten!";
	size_t size = ft_strlen(src);
	printf("Source is: %s\nDestination before stlcpy: %s\nSize is: %zu\n", src,
		dst, size);
	size_t result = ft_strlcpy(dst, src, size);
	printf("Lenght after strlcpy is: %zu\nDestination becomes: %s\n", result,
		dst);
	return (0);
} */
