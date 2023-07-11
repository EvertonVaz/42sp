/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:11:30 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/06 20:45:35 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char *s1;
	char *s2;
	char *s3;
	char *s4;
	char s5[] = {'a', 'b', 'c', -10, -20, '\0'};
	char *s6;
	char *s7;

	s1 = calloc(10, sizeof(char));
	s2 = calloc(8, sizeof(char));
	s3 = calloc(10, sizeof(char));
	s4 = calloc(10, sizeof(char));
	s6 = calloc(10, sizeof(char));
	s7 = calloc(1, sizeof(char));
	s1 = "abcdefghi";
	s2 = "abcdefg";
	s3 = "abcdEfghi";
	s4 = "ab0defghi";
	s6 = "abcdefghi"; // s6 is the same of s1
	s7 = "";
	printf("s1: %s, s2: %s, s3: %s, s4: %s, s5: %s, s6: %s, s7: %s\n", s1, s2, s3, s4, s5, s6, s7);
	printf("ft_strcmp(s1, s2)\t= %d\noriginal strcmp(s1, s2)\t= %d\n------------------------------\n", ft_strcmp(s1, s2), strcmp(s1, s2));
	printf("ft_strcmp(s1, s3)\t= %d\noriginal strcmp(s1, s3)\t= %d\n------------------------------\n", ft_strcmp(s1, s3), strcmp(s1, s3));
	printf("ft_strcmp(s1, s4)\t= %d\noriginal strcmp(s1, s4)\t= %d\n------------------------------\n", ft_strcmp(s1, s4), strcmp(s1, s4));
	printf("ft_strcmp(s1, s5)\t= %d\noriginal strcmp(s1, s5)\t= %d\n------------------------------\n", ft_strcmp(s1, s5), strcmp(s1, s5));
	printf("ft_strcmp(s1, s6)\t= %d\noriginal strcmp(s1, s6)\t= %d\n------------------------------\n", ft_strcmp(s1, s6), strcmp(s1, s6));
	printf("ft_strcmp(s1, s7)\t= %d\noriginal strcmp(s1, s7)\t= %d\n------------------------------\n", ft_strcmp(s1, s7), strcmp(s1, s7));
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
	return(0);
}
