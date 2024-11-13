/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:42:10 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/16 18:56:50 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = -1;
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (!d && !s)
		return (0);
	while (++i < size)
		d[i] = s[i];
	return (dst);
}

/* int main()
{
	char src[] = "Hello, world!";
	char dest[20] = "overwrite";

	ft_memcpy(dest, src, sizeof(src));
	printf("Source is: %s\nDest after 'Memory Copy' is: %s\n", src, dest);

	return (0);
} */
