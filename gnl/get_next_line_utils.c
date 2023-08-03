/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:27:39 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/03 20:55:25 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_bzero(void *src, size_t n)
{
	char	*ptr;

	ptr = src;
	while (n--)
		*ptr++ = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	total_size;

	total_size = nmemb * size;
	if (nmemb == 0 || size == 0 || (total_size / size != nmemb))
		return (malloc(0));
	alloc = malloc(total_size);
	if (alloc != NULL)
		ft_bzero(alloc, total_size);
	return (alloc);
}

char	*ft_strchr(const char *s, int c)
{
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
	while (s[i] != '\0')
		i++;
	return (i);
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
