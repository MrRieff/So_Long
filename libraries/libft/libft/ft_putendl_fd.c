/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_ft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:49:00 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/12 17:56:41 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, &*s++, 1);
	write(fd, "\n", 1);
}
/* int main()
{
  ft_putendl_fd("This is a test", 1);
  return (0);
} */