/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:27:39 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/07 14:37:50 by egeraldo         ###   ########.fr       */
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
		while (total_size--)
			*alloc = 0;
	return ((void *)alloc);
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

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	while (src[i] && dest_len + i + 1 <= n)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	if (n < dest_len)
		return (src_len + n);
	else
		return (src_len + dest_len);
}