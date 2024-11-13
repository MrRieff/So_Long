/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:28:10 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/18 16:02:28 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = -1;
	if (size == 0 && !dst)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len || size == 0)
		return (size + src_len);
	while (src[++i] && i + dst_len < size - 1)
		dst[dst_len + i] = src[i];
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

/* int	main(void)
{
	char	*src = "This is a src message!";;
	char	dst[] = "This is a dst message! ";
	size_t	size;
	size_t	result;


	size = (ft_strlen(src) + ft_strlen(dst) + 2);
	printf("Source is: %s\nDest Before StrlCat is: %s\nSize is: %zu\n", src,
		dst, size);
	result = ft_strlcat(dst, src, size);
	printf("Lenght is: %zu\nDest Became: %s\n", result, dst);
	return (0);
} */
