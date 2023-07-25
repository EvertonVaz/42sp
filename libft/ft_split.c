/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:37:26 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/25 15:30:05 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *str, char sep)
{
	size_t	index;
	size_t	words;

	index = 0;
	words = 0;
	while (str[index] != '\0')
	{
		while (str[index] == sep)
			index++;
		if (str[index] != sep && str[index] != '\0')
			words++;
		while (str[index] != sep && str[index] != '\0')
			index++;
	}
	return (words);
}

static size_t	len(const char *str, char sep, size_t i)
{
	size_t	size;

	size = 0;
	while (str[i] != sep && str[i++] != '\0')
		size++;
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	w;
	size_t	words;
	size_t	size_words;

	words = ft_count_words(s, c);
	i = 0;
	w = 0;
	split = (char **)ft_calloc((words + 1), sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (w < words)
	{
		while (s[i] == c)
			i++;
		size_words = len(s, c, i);
		split[w] = ft_substr(s, i, size_words);
		if (split[w++] == NULL)
			return (NULL);
		i += size_words;
	}
	split[w] = 0;
	return (split);
}
