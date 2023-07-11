/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:11:51 by emendes-          #+#    #+#             */
/*   Updated: 2023/06/07 19:36:17 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <ctype.h>

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


size_t	strlcat(char *dst, const char *src, size_t size);

int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_strstr(char *str, char *to_find);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int	ft_strlen(char *str);



int	same_sign(int a, int b)
{
	if (a < 0 && b < 0)
		return (0);
	else if (a > 0 && b > 0)
		return (0);
	else if (a == 0 && b == 0)
		return (0);
	return (1);
}

int main(void)
{
	printf("-- Exercício 00: ");
	char str0[] = "string";
	char str1[] = "string1";
	char str2[] = "abcdef";
	char str3[] = "fedcba";
	char str4[] = {-123, -56, 6, 32, 64, 65, 66, 0};
	char str5[] = "abcdefghijadofhiasdfj";
	char str6[] = "abcdefghijadfedcba";

	int ret0 = strcmp(str0, str1);
	int ret1 = ft_strcmp(str0, str1);

	if (same_sign(strcmp(str0, str1), ft_strcmp(str0, str1)))
		printf("KO, expected %i got %i\n", ret0, ret1);
	else if (same_sign((ret0 = strcmp(str1, str2)), (ret1 = ft_strcmp(str1, str2))))
		printf("KO, expected %i got %i\n", ret0, ret1);
	else if (same_sign((ret0 = strcmp(str2, str3)), (ret1 = ft_strcmp(str2, str3))))
		printf("KO, expected %i got %i\n", ret0, ret1);
	else if (same_sign((ret0 = strcmp(str3, str4)), (ret1 = ft_strcmp(str3, str4))))
		printf("KO, expected %i got %i\n", ret0, ret1);
	else if (same_sign((ret0 = strcmp(str5, str6)), (ret1 = ft_strcmp(str5, str6))))
		printf("KO, expected %i got %i\n", ret0, ret1);
	else
		printf("OK\n");

	printf("-- Exercício 01: ");
	int str0l = strlen(str0);
	int str1l = strlen(str1);

	if (same_sign((ret0 = strncmp(str0, str1, str0l)), (ret1 = ft_strncmp(str0, str1, str0l))))
		printf("KO, test00 expected %i got %i\n", ret0, ret1);
	else if (same_sign((ret0 = strncmp(str2, str3, 0)), (ret1 = ft_strncmp(str2, str3, 0))))
		printf("KO, test01 expected %i got %i\n", ret0, ret1);
	else if (same_sign((ret0 = strncmp(str1, str2, str1l)), (ret1 = ft_strncmp(str1, str2, str1l))))
		printf("KO, test02 expected %i got %i\n", ret0, ret1);
	else if (same_sign((ret0 = strncmp(str2, str3, 2)), (ret1 = ft_strncmp(str2, str3, 2))))
		printf("KO, test03 expected %i got %i\n", ret0, ret1);
	else if (same_sign((ret0 = strncmp(str3, str4, 2)), (ret1 = ft_strncmp(str3, str4, 2))))
		printf("KO, test04 expected %i got %i\n", ret0, ret1);
	else if (same_sign((ret0 = strncmp(str3, str4, 100)), (ret1 = ft_strncmp(str3, str4, 100))))
		printf("KO, test05 expected %i got %i\n", ret0, ret1);
	else if (same_sign((ret0 = strncmp(str0, str1, 100)), (ret1 = ft_strncmp(str0, str1, 100))))
		printf("KO, test06 expected %i got %i\n", ret0, ret1);
	else
		printf("OK\n");

	printf("-- Exercício 02: ");
	char buffer0[100];
	char buffer1[100];

	int i = 0;
	while (i < 100)
	{
		buffer0[i] = 'a';
		buffer1[i] = 'a';
		++i;
	}


	strcpy(buffer0, str1);
	strcpy(buffer1, str1);

	if (strcat(buffer1, str0), buffer0 != ft_strcat(buffer0, str0))
		printf("KO, test00 wrong return\n");
	else if (strcmp(buffer0, buffer1) != 0)
		printf("KO, test00 expected %s got %s\n", buffer1, buffer0);
	else if (strcat(buffer1, "ba ba ta ta"), buffer0 != ft_strcat(buffer0,  "ba ba ta ta"))
		printf("KO, test00 wrong return\n");
	else if (strcmp(buffer0, buffer1) != 0)
		printf("KO, test00 expected %s got %s\n", buffer1, buffer0);
	else
		printf("OK\n");

	printf("-- Exercício 03: ");

	i = 0;
	while (i < 100)
	{
		buffer0[i] = 'a';
		buffer1[i] = 'a';
		++i;
	}

	strcpy(buffer0, str1);
	strcpy(buffer1, str1);

	if (strncat(buffer1, str3, 3), buffer0 != ft_strncat(buffer0, str3, 3))
		printf("KO, test00 wrong return\n");
	else if (strcmp(buffer0, buffer1) != 0)
		printf("KO, test00 expected %s got %s\n", buffer1, buffer0);
	else if (strncat(buffer1, str1, 100), buffer0 != ft_strncat(buffer0, str1, 100))
		printf("KO, test01 wrong return\n");
	else if (strcmp(buffer0, buffer1) != 0)
		printf("KO, test01 expected %s got %s\n", buffer1, buffer0);
	else
		printf("OK\n");


	printf("-- Exercício 04: ");
	char findin0[] = "asdfasdfstringasaa";
	char findin1[] = "string aaa aaa string";
	char findin2[] = "1349813-2139485-1234";

	if (strstr(findin0, "string") != ft_strstr(findin0, "string"))
		printf("KO test00\n");
	else if (strstr(findin1, "string") != ft_strstr(findin1, "string"))
		printf("KO test01\n");
	else if (strstr(findin2, "213") != ft_strstr(findin2, "213"))
		printf("KO test02\n");
	else if (strstr(findin0, "213") != ft_strstr(findin0, "213"))
		printf("KO test03\n");
	else if (strstr(findin2, "555555") != ft_strstr(findin2, "555555"))
		printf("KO test04\n");
	else if (strstr(findin2, "") != ft_strstr(findin2, ""))
		printf("KO test05\n");
	else if (strstr(findin0, "123") != ft_strstr(findin0, "123"))
		printf("KO test06\n");
	else if (strstr(findin0, "asdfasdfstringasa") != ft_strstr(findin0, "asdfasdfstringasa"))
		printf("KO test07\n");
	else if (strstr("", "") != ft_strstr("", ""))
		printf("KO test08\n");
	else
		printf("OK\n");

	printf("-- Exercício 05: ");
	i = 0;
	while (i < 100)
	{
		buffer0[i] = 0;
		buffer1[i] = 0;
		++i;
	}
	strcpy(buffer0, str1);
	strcpy(buffer1, str1);
	unsigned int ret0l;
	unsigned int ret1l;

	if ((ret1l = strlcat(buffer1, str0, 7)) != (ret0l = ft_strlcat(buffer0, str0, 7)))
		printf("KO1, test00 wrong return expected %i got %i\n", ret1l, ret0l);
	else if (strncmp(buffer0, buffer1, 100) != 0)
		printf("KO2, test00 expected %s got %s\n", buffer1, buffer0);

	else if ((ret1l = strlcat(buffer1, str0, 20)) != (ret0l = ft_strlcat(buffer0, str0, 20)))
		printf("KO3, test01 wrong return expected %i got %i\n", ret1l, ret0l);
	else if (strncmp(buffer0, buffer1, 100) != 0)
		printf("KO4, test01 expected %s got %s\n", buffer1, buffer0);

	else if ((ret1l = strlcat(buffer1, str2, 1)) != (ret0l = ft_strlcat(buffer0, str2, 1)))
		printf("KO5, test02 wrong return expected %i got %i\n", ret1l, ret0l);
	else if (strncmp(buffer0, buffer1, 100) != 0)
		printf("KO6, test02 expected %s got %s\n", buffer1, buffer0);
	else
		printf("OK\n");

}

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (*str != '\0')
// 	{
// 		str++;
// 		i++;
// 	}
// 	return (i);
// }

// unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
// {
// 	unsigned int	dest_len;
// 	unsigned int	src_len;
// 	unsigned int	total_len;
// 	unsigned int	i;

// 	dest_len = ft_strlen(dest);
// 	src_len = ft_strlen(src);
// 	total_len = dest_len + src_len;
// 	if (src_len > size)
// 		return (total_len);
// 	i = 0;
// 	while (src[i] != '\0' && i < (size - dest_len - 1))
// 	{
// 		dest[dest_len + i] = src[i];
// 		i++;
// 	}
// 	dest[dest_len + i] = '\0';
// 	return (total_len);
// }

// char	*ft_strstr(char *str, char *to_find)
// {
// 	int	i;
// 	int	temp;

// 	if (*to_find == '\0')
// 		return (str);
// 	while (*str != '\0')
// 	{
// 		if (*str == *to_find)
// 		{
// 			i = 0;
// 			temp = 0;
// 			while (to_find[i] != '\0')
// 			{
// 				if (str[i] != to_find[i])
// 					temp = 1;
// 				i++;
// 			}
// 			if (temp == 0)
// 				return (str);
// 		}
// 		str++;
// 	}
// 	return (0);
// }

// char	*ft_strncat(char *dest, char *src, unsigned int nb)
// {
// 	char	*temp;

// 	temp = dest;
// 	while (*dest)
// 	{
// 		dest++;
// 	}
// 	while (*src && nb > 0)
// 	{
// 		*dest = *src;
// 		dest++;
// 		src++;
// 		nb--;
// 	}
// 	*dest = '\0';
// 	return (temp);
// }

// char	*ft_strcat(char *dest, char *src)
// {
// 	char	*temp;

// 	temp = dest;
// 	while (*dest)
// 	{
// 		dest++;
// 	}
// 	while (*src)
// 	{
// 		*dest = *src;
// 		dest++;
// 		src++;
// 	}
// 	*dest = '\0';
// 	return (temp);
// }

// int	ft_strncmp(char *s1, char *s2, unsigned int n)
// {
// 	while (n > 0 && (*s1 != '\0' || *s2 != '\0'))
// 	{
// 		if (*s1 != *s2)
// 			return (*(unsigned char *)s1 - *(unsigned char *)s2);
// 		s1++;
// 		s2++;
// 		n--;
// 	}
// 	return (0);
// }

// int	ft_strcmp(char *s1, char *s2)
// {
// 	while (*s1 != '\0' && *s1 == *s2)
// 	{
// 		s1++;
// 		s2++;
// 	}
// 	return (*(unsigned char *)s1 - *(unsigned char *)s2);
// }
