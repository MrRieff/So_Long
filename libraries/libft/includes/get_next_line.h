/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:11:45 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/05/14 12:46:15 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
# endif

# include "fcntl.h" //for open and read
# include "stdlib.h"
# include "unistd.h"
# include <stdio.h>

size_t	ft_nwllen(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		organizer(char *buffer);
char	*get_next_line(int fd);
void	ft_bzero_gnl(void *s, size_t size);

#endif