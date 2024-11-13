/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:25:32 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/12 17:34:08 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (!s || !f)
		return (NULL);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	i = -1;
	while (str[++i])
		str[i] = f(i, str[i]);
	str[i++] = '\0';
	return (str);
}

/* char	map_function(unsigned int index, char c)
{
		if((index < 'A' && index > 'Z') || (index < 'a' && index > 'z'))
			return (0);
	return (c - 1);
}

int	main(void) {
	const char *sample_string = "Hello, world!";
	char *result = ft_strmapi(sample_string, &map_function);

	if (result != NULL) {
		printf("Original string: %s\n", sample_string);
		printf("Mapped string: %s\n", result);
		free(result);
	} else {
		printf("Error: ft_strmapi returned NULL\n");
	}
	return (0);
} */