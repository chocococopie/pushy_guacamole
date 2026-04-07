/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dishagia <dishagia@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 05:22:57 by dishagia          #+#    #+#             */
/*   Updated: 2026/04/07 19:07:52 by dishagia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

char	*copy_word(const char *s, int start, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	fill_one_word(char **result, const char *s, char c, int *index)
{
	int	start;
	int	len;

	start = 0;
	while (s[start] == c)
		start++;
	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	result[*index] = copy_word(s, start, len);
	if (!result[*index])
	{
		while (*index > 0)
			free(result[--(*index)]);
		free(result);
		return (0);
	}
	(*index)++;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < words)
	{
		if (!fill_one_word(result, s, c, &i))
			return (NULL);
	}
	result[i] = NULL;
	return (result);
}
