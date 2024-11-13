/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:49:19 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/12 22:36:40 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t size)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (size-- > 0)
		*str++ = 0;
}
/* int	main(void)
{
	char	buffer[10];
	int		i;

	i = -1;
	printf("Buffer before bzero:\n");
	while (++i < 10)
	{
		buffer[i] = 'A' + i;
		printf("%c ", buffer[i]);
	}
	printf("\n");
	ft_bzero(buffer, 10);
	printf("Buffer after bzero:\n");
	i = -1;
	while (++i < 10)
		printf("%c ", buffer[i]);
	printf("\n");
	return (0);
} */
