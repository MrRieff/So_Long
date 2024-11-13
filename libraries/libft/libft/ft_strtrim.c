/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:46:04 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/16 19:46:07 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	if (start > end || ft_strlen(s1) == 0)
	{
		str = malloc(1);
		str[0] = '\0';
		return (str);
	}
	str = malloc(end - start * sizeof(char) + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 2);
	return (str);
}

/* int main()
{
  char *str = "   xxx   xxx";
  char *set = " x";
  char *trimmed_str = ft_strtrim(str, set);
  printf("Original String: %s\nSet: %s\nTrimmed String: %s\n", str, set,
	trimmed_str);
  free (trimmed_str);
  return (0);
} */