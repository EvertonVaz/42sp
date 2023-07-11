/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex10.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 01:08:49 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/06 20:21:14 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/string.h>

#ifndef HAVE_STRLCAT
/*
 * '_cups_strlcat()' - Safely concatenate two strings.
 */

size_t                  /* O - Length of string */
strlcat(char       *dst,        /* O - Destination string */
              const char *src,      /* I - Source string */
          size_t     size)      /* I - Size of destination string buffer */
{
  size_t    srclen;         /* Length of source string */
  size_t    dstlen;         /* Length of destination string */


 /*
  * Figure out how much room is left...
  */

  dstlen = strlen(dst);
  size   -= dstlen + 1;

  if (!size)
    return (dstlen);        /* No room, return immediately... */

 /*
  * Figure out how much room is needed...
  */

  srclen = strlen(src);

 /*
  * Copy the appropriate amount...
  */

  if (srclen > size)
    srclen = size;

  memcpy(dst + dstlen, src, srclen);
  dst[dstlen + srclen] = '\0';

  return (dstlen + srclen);
}
#endif /* !HAVE_STRLCAT */

#ifndef HAVE_STRLCPY
/*
 * '_cups_strlcpy()' - Safely copy two strings.
 */

size_t                  /* O - Length of string */
strlcpy(char       *dst,        /* O - Destination string */
              const char *src,      /* I - Source string */
          size_t      size)     /* I - Size of destination string buffer */
{
  size_t    srclen;         /* Length of source string */


 /*
  * Figure out how much room is needed...
  */

  size --;

  srclen = strlen(src);

 /*
  * Copy the appropriate amount...
  */

  if (srclen > size)
    srclen = size;

  memcpy(dst, src, srclen);
  dst[srclen] = '\0';

  return (srclen);
}
#endif /* !HAVE_STRLCPY */

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size);

// unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
// {
// 	unsigned int	strlen;
// 	unsigned int	i;

// 	strlen = 0;
// 	i = 0;
// 	while (src[i])
// 	{
// 		strlen++;
// 		i++;
// 	}
// 	if (size < 1)
// 		return (strlen);
// 	i = 0;
// 	while (src[i] && i < size - 1)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (strlen);
// }

int				main(void)
{
	int 	src_size;
	char 	*src;
	char 	*dest;

	src = calloc(11, sizeof(char));
	dest = calloc(8, sizeof(char));
	src = "alo galera";
	src_size = ft_strlcpy(dest, src, 8);
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);
	printf("src_size: %d\n", src_size);
	size_t ret0s, ret1s;

	printf("-- Exercicio 10: ");

	char buffer0[100];
	char buffer1[100];
	char str0[] = "Ninguem liga";
	char str1[] = "outra 777 sad2 func";
	char str2[] = "striGn Mais doida\n doia\\varioschar\r\r\r";
	char str3[] = "";
	size_t str0l = strlen(str0);
	size_t str1l = strlen(str1) + 10;
	size_t str2l = strlen(str2) - 7;
	size_t str3l = strlen(str3);

	if (ret0s = ft_strlcpy(buffer0, str0, str0l), strlcpy(buffer1, str0, str0l), strncmp(buffer0, buffer1, str0l) != 0)
	{
		printf("KO1, expected %s got %s\n", buffer1, buffer0);
		printf("str - %s, buffer0 - %s, buffer0 - %s, len - %ld", str0, buffer0, buffer1, str0l);
	}
	else if (ret1s = strlcpy(buffer0, str0, str0l), ret0s != ret1s)
	{
		printf("KO2, expected return %zu got %zu in str0\n", ret1s, ret0s);
		printf("str - %s, buffer0 - %s, buffer1 - %s, len - %ld", str0, buffer0, buffer1, str0l);
	}
	else if (ret0s = ft_strlcpy(buffer0, str1, str1l), strlcpy(buffer1, str1, str1l), strncmp(buffer0, buffer1, str1l) != 0)
		printf("KO3, expected %s got %s", buffer1, buffer0);
	else if (ret1s = strlcpy(buffer0, str1, str1l), ret0s != ret1s)
		printf("KO4, expected return %zu got %zu in str1", ret1s, ret0s);

	else if (ret0s = ft_strlcpy(buffer0, str2, str2l), strlcpy(buffer1, str2, str2l), strncmp(buffer0, buffer1, str2l) != 0)
		printf("KO5, expected %s got %s", buffer1, buffer0);
	else if (ret1s = strlcpy(buffer0, str2, str2l), ret0s != ret1s)
		printf("KO6, expected return %zu got %zu in str2", ret1s, ret0s);

	else if (ret0s = ft_strlcpy(buffer0, str3, str3l), strlcpy(buffer1, str3, str3l), strncmp(buffer0, buffer1, str3l) != 0)
		printf("KO7, expected %s got %s", buffer1, buffer0);
	else if (ret1s = strlcpy(buffer0, str3, str3l), ret0s != ret1s)
		printf("KO8, expected return %zu got %zu in str3", ret1s, ret0s);

	else
		printf("OK");
	printf("\n");
	return(0);
}
