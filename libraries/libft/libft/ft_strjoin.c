/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:04:46 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/16 19:44:49 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc(s1_len + s2_len * sizeof(char) + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, (char *)s1, s1_len + 1);
	ft_strlcat(result, (char *)s2, s2_len + s1_len + 1);
	return (result);
}
/* int main()
{
  char *s1 = "tripouille";
  char *s2 = "42";
  char *result = ft_strjoin(s1, s2);
  printf("S1 is: %s\nS2 is: %s\nResult is: %s\n", s1, s2, result);
  free(result);
  return (0);
} */