/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:27:39 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/11 12:18:02 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*alloc;
	size_t	total_size;

	total_size = nmemb * size;
	if (nmemb == 0 || size == 0 || (total_size / size != nmemb))
		return (malloc(0));
	alloc = malloc(total_size);
	if (alloc != NULL)
		while (total_size)
			alloc[--total_size] = 0;
	return ((void *)alloc);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != (char)c && *s != '\0')
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		len;

	len = ft_strlen(src);
	new = ft_calloc(len + 1, sizeof(char));
	if (!new)
		return (0);
	len = -1;
	while (src[++len])
		new[len] = src[len];
	new[len] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*aux;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *)ft_calloc(len, sizeof(char));
	if (join == NULL)
		return (NULL);
	aux = join;
	while (*s1 != '\0')
		*aux++ = *s1++;
	while (*s2 != '\0')
		*aux++ = *s2++;
	*aux = '\0';
	return (join);
}
