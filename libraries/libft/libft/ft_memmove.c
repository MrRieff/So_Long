/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:58:19 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/20 12:08:41 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest1;
	const unsigned char	*src1;

	dest1 = (unsigned char *)dest;
	src1 = (unsigned const char *)src;
	if (dest == src || n == 0)
		return (dest);
	if (dest > src)
	{
		while (n--)
			dest1[n] = src1[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/* int main()
{
  char source[] = "THIS IS THE NEW STRING";
  char destination[] = "THIS IS THE OLD STRING";
  int size = ft_strlen(source);

  printf("BEFORE MEMMOVE:\n\nSOURCE IS:
		%s\nDESTINATION IS: %s\nSIZE IS: %i\n",
	source, destination, size);

  ft_memmove(destination, source, size);
  printf("\nAFTER MEMMOVE:\n\nDESTINATION IS: %s\n",
		destination);

  return (0);
} */
