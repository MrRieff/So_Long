/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:11:40 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/08/28 12:08:50 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*s;

	s = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		ft_bzero_gnl(buffer, BUFFER_SIZE);
		return (NULL);
	}
	if (!buffer[0])
		read(fd, buffer, BUFFER_SIZE);
	while (buffer[0])
	{
		s = ft_strjoin_gnl(s, buffer);
		if (!s)
			return (NULL);
		if (organizer(buffer) == 1)
			break ;
		if (read(fd, buffer, BUFFER_SIZE) < 0)
		{
			free(s);
			return (NULL);
		}
	}
	return (s);
}
