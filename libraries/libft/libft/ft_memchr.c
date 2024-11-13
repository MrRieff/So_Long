/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:16:47 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/15 17:44:08 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int chr, size_t size)
{
	size_t			i;
	unsigned char	*str;

	i = -1;
	str = (unsigned char *)s;
	while (++i < size)
		if (str[i] == (unsigned char)chr)
			return ((void *)str + i);
	return (NULL);
}
/* int main()
{
  char str[] = "This is a test!";
  char letter = 's';
  int len = ft_strlen(str);

  printf("Before memchr: %s\n", str);

  char *ret = ft_memchr(str, letter, len);

  printf("After memchr: %s\n", ret);

  return (0);
} */
