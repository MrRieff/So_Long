/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:52:18 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/16 19:49:23 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	word_count(const char *str, char c)
{
	int	words;
	int	separator;

	words = 0;
	separator = 0;
	while (*str)
	{
		if (*str != c && separator == 0)
		{
			separator = 1;
			words++;
		}
		else if (*str == c)
			separator = 0;
		str++;
	}
	return (words);
}

static char	*word_dup(const char *s, int start, int end)
{
	char	*word;
	size_t	i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	word;
	int		start;
	char	**split;

	start = -1;
	i = -1;
	word = 0;
	split = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!split || !s)
		return (0);
	while (++i <= (int)ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == (int)ft_strlen(s)) && start >= 0)
		{
			split[word++] = word_dup(s, start, i);
			start = -1;
		}
	}
	split[word] = 0;
	return (split);
}

/* int main()
{
  char *str = "I Hope This Returns Multiple Words Divided By New Lines";
  char c = ' ';
  char **split = ft_split(str, c);
  int counter = ft_word_counter(str, c);
  int i;

  printf("Original String: %s\nCharacter is: SPACE\nString Split:\n", str);

  i = 0;
  while(*split++ && i <= counter)
		printf("%s\n", *split);
  free(split);
  return (0);
} */
