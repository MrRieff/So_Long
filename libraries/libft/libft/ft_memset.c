/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:27:33 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/09 15:41:32 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *ptr, int c, size_t size)
{
	size_t	i;
	char	*result;

	i = -1;
	result = (char *)ptr;
	while (++i < size)
		result[i] = (char)c;
	return (ptr);
}
/* int main()
{
	char str[] = "This is a test!";
	char letter = 'a';
	printf("Before memset: %s\n", str);

	ft_memset(str, letter, ft_strlen(str));

	printf("After memset: %s\n", str);
	return (0);
} */
