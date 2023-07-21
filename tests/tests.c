/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:04:34 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/19 14:36:51 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"
#include <stddef.h>

int	main(void)
{
	char *src = "Hello World!";
	char dest[20];
	
	int test = ft_strlcpy(dest, src, 20);
	printf("%s, %d\n", dest, test);

	ft_memset(dest, 'a', 20);
	printf("ft_memset - %s\n", dest);
	ft_memset(dest, 48, 20);
	printf("ft_memset - %s\n", dest);
	ft_bzero(dest, 13);
	printf("ft_bzero - %s\n", dest);
	ft_memcpy(dest, src, ft_strlen(dest));
	printf("ft_memcpy - %s\n", dest);
	char *a = "ft_memmove";
	char b[20];
	ft_memmove(b, a, ft_strlen(dest));
	printf("ft_memmove - %s\n", b);
	char c[100] = "Hello world!";
	char d[15] = "Hello world";
	size_t n = ft_strlcat(c, d, sizeof(d));
	printf("ft_strlcat - %s, %zu, %lu\n", c, n, sizeof(d));
	int e = 'l';
	char *chr = ft_strrchr(src, e);
	printf("ft_strrchr - a letra %c foi encontrada na posicao %ld\n", (char)e, chr - src);
	
	printf("ft_strncmp - %d\n", ft_strncmp(c, d, 5));
	
	printf("ft_memchr - encontrou a letra %c na posicao %ld\n", (char)e, ft_memchr(d, e, ft_strlen(d)) - d);
	
	printf("ft_memcmp - %d\n", ft_memcmp(c, d, 20));

	printf("ft_strntr - %s\n", ft_strnstr("Hello", "lo", 50));

	char *str = ft_calloc(15, sizeof(char));
	str = "Hello World";
	printf("ft_callor - %s\n", str);
	
	char *new = ft_strdup(str);
	printf("ft_strdup - %s\n", new);
	return (0);
}