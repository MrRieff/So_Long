/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:24:20 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/20 12:09:11 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	unsigned int	str_len;
	unsigned int	i;

	i = 0;
	str_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if ((start >= str_len) || len == 0)
		return (ft_strdup(""));
	if (str_len - start >= len)
		sub_str = malloc(len * sizeof(char) + 1);
	else
		sub_str = malloc((str_len - start + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	while (s[start] && start < str_len && i < len)
		sub_str[i++] = s[start++];
	sub_str[i] = '\0';
	return (sub_str);
}

/* int main()
{
	char *str = "i just want this part #############";
	int start = 5;
	size_t len = 4;
	char *result = ft_substr(str, start, len);
	printf("Original String is: %s\nStarts at: %i\nLenght is: %zu\nResult is:
		%s\n", str, start, len, result);
	free(result);
	return (0);
} */