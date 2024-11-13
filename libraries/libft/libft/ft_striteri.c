/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:35:04 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/15 14:04:31 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = -1;
	while (s[++i])
		f(i, s + i);
}

/* void	example_function(unsigned int index, char *c)
{
	printf("Character at index %u is %c\n", index, *c);
}

int	main(void)
{
	char test_string[] = "Hello, world!";

	ft_striteri(test_string, example_function);

	return (0);
} */