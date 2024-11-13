/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:11:36 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/05/14 12:46:22 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	ft_bzero_gnl(void *s, size_t size)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (size-- > 0)
		*str++ = 0;
}

size_t	ft_nwllen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i + (s[i] == '\n'));
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	result = malloc(ft_nwllen(s1) + ft_nwllen(s2) + 1 * sizeof(char));
	if (!result)
		return (NULL);
	j = 0;
	i = 0;
	while (s1 && s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j] && s2[j] != '\n')
		result[i++] = s2[j++];
	if (s2[j] == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	free(s1);
	return (result);
}

int	organizer(char *buffer)
{
	int	i;
	int	j;
	int	is_nwl;

	i = 0;
	j = 0;
	is_nwl = 0;
	while (buffer[i])
	{
		if (is_nwl)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			is_nwl = 1;
		buffer[i++] = '\0';
	}
	return (is_nwl);
}
