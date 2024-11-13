/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:23:39 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/16 19:44:27 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*result;

	i = -1;
	result = malloc(ft_strlen(str) * sizeof(char) + 1);
	if (!result)
		return (NULL);
	while (str[++i])
		result[i] = str[i];
	result[i] = '\0';
	return (result);
}

/* int main()
{
	char *str = "Isto e um teste";
	char *result = ft_strdup(str);

	printf("Original String: %s\nCopied String: %s\n", str, result);
	return (0);
} */
